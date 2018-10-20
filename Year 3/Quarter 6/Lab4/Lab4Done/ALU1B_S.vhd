-- or
library IEEE;
use IEEE.std_logic_1164.all;

entity or is
        port (
	        a: in STD_LOGIC;
	        b: in STD_LOGIC;
                c : out STD_LOGIC
	);
end or;

architecture behavioral of or_2 is
begin
  c <= (a or b) after 2 ns;
end behavioral;

-- behavioral model of 1-bit ALU w/ subtraction

library IEEE;
use IEEE.std_logic_1164.all;

entity ALU1B_S is
 port(a,b,CarryIn,binvert : in std_logic;
      Operation : in std_logic_vector (1 downto 0);
         Result, CarryOut : out std_logic);
end ALU1B_S;

architecture behavioral of ALU1B_S is

component and
	port(a,b : in STD_LOGIC;
		c : out STD_LOGIC);
end component;

component xor
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
  CarryOut <= ((a and br) or (a and CarryIn) or (br and CarryIn)) after gate_delay;
end behavioral;