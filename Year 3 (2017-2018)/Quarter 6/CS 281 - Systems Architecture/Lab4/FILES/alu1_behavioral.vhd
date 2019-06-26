-- behavioral model of 1-bit ALU

library IEEE;
use IEEE.std_logic_1164.all;

entity alu1b is
 port(a,b,CarryIn : in STD_LOGIC;
      Operation : in STD_LOGIC_vector (1 downto 0);
         Result, CarryOut : out STD_LOGIC);
end alu1b;

architecture behavioral of alu1b is

constant gate_delay: Time:=1 ns;

begin
with Operation select
  Result <= (a and b) after gate_delay when "00",
            (a or b) after gate_delay when "01",
            (a xor b xor CarryIn) after gate_delay when "10",
            'X' after gate_delay when others;
  CarryOut <= ((a and b) or (a and CarryIn) or (b and CarryIn)) after gate_delay;
end behavioral;

         
