-- behavioral model of 1-bit ALU w/overflow detection

library IEEE;
use IEEE.std_logic_1164.all;

entity ALU1B_S_O is
 port(a,b,CarryIn,binvert : in std_logic;
      Operation : in std_logic_vector (1 downto 0);
         Result, CarryOut, Overflow : out std_logic);
end ALU1B_S_O;

architecture behavioral of alu1sob is

component xor
	port(a,b : in STD_LOGIC;
		c : out STD_LOGIC);
end component;

component and
	port(a,b : in STD_LOGIC;
		c : out STD_LOGIC);
end component;

constant gate_delay: Time:=1 ns;

begin
br <= b xor binvert;

with Operation select
  Result <= (a and br) after gate_delay when "00",
            (a or br) after gate_delay when "01",
            (a xor br xor CarryIn) after gate_delay when "10",
            'X' after gate_delay when others;
  CarryOutt <= ((a and br) or (a and CarryIn) or (br and CarryIn)) after gate_delay;
  CarryOut  <= CarryOutt;
  Overflow  <= (CarryIn xor CarryOutt);

end behavioral;