-- structural model of the 1-bit ALU

library IEEE;
use IEEE.std_logic_1164.all;

entity alu1s is
 port(a,b,CarryIn : in STD_LOGIC;
      Operation : in STD_LOGIC_vector (1 downto 0);
         Result, CarryOut : out STD_LOGIC);
end alu1s;

architecture structural of alu1s is

component and_2
  port(a,b : in STD_LOGIC;
         c : out STD_LOGIC);
end component;

component or_2
  port(a,b : in STD_LOGIC;
         c : out STD_LOGIC);
end component;

component full_adder
 port(a,b,c_in : in STD_LOGIC;
         sum,c_out: out STD_LOGIC);
end component;

component mux41
        port(I0,I1,I2,I3 : in STD_LOGIC;
                 Sel : in STD_LOGIC_vector(1 downto 0);
                 Z : out STD_LOGIC);
end component;

signal s1, s2, s3 : STD_LOGIC;
signal s4 : STD_LOGIC := 'X';

begin
  AG  : and_2 port map(a => a, b => b, c => s1);
  OG  : or_2 port map(a => a, b => b, c => s2);
  FA  : full_adder port map(a => a, b => b, c_in => CarryIn, sum => s3, c_out => CarryOut);
  MUX : mux41 port map(I0 => s1, I1 => s2, I2 => s3, I3 => s4, Sel => Operation, Z => Result);

end structural;

         
