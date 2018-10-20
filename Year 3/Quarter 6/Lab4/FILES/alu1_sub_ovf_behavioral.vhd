-- behavioral model of 1-bit ALU with subtraction and overflow detection

library IEEE;
use IEEE.std_logic_1164.all;

entity alu1sob is
 port(a,b,CarryIn,binvert : in std_logic;
      Operation : in std_logic_vector (1 downto 0);
         Result, CarryOut, Overflow : out std_logic);
end alu1sob;

architecture behavioral of alu1sob is

constant gate_delay: Time:=1 ns;

signal br, CarryOutt : std_logic;

begin
br <= b xor binvert;

with Operation select
  Result <= (a and br) after gate_delay when "00",
            (a or br) after gate_delay when "01",
            (a xor br xor CarryIn) after gate_delay when "10",
            'X' after gate_delay when others;
--CarryOut  <= ((a and br) or (a and CarryIn) or (br and CarryIn)) after gate_delay;
--Overflow  <= (CarryIn xor CarryOut);
  CarryOutt <= ((a and br) or (a and CarryIn) or (br and CarryIn)) after gate_delay;
  CarryOut  <= CarryOutt;
  Overflow  <= (CarryIn xor CarryOutt);

end behavioral;
