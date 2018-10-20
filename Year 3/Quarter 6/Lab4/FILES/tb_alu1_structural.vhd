-- TEST BENCH 1-BIT ALU STRUCTURAL

library IEEE;
use IEEE.std_logic_1164.all;

entity tb_alu1s is
end entity;

architecture structural of tb_alu1s is

component alu1s
 port(
  a,b,CarryIn : in STD_LOGIC;
      Operation : in STD_LOGIC_vector (1 downto 0);
         Result, CarryOut : out STD_LOGIC
  );
end component;

  signal myA, myB, myC, myRes, myC_out : STD_LOGIC;
  signal myOp : STD_LOGIC_vector (1 downto 0);

begin

   TB: alu1s
    port map (
    a => myA,
    b => myB, 
    CarryIn => myC,
    Operation => myOp,
    Result => myRes,
    CarryOut => myC_out
    );
   
  myOp <= "10" after   0 ns, "00" after 200 ns;

  myA <= '0' after   0 ns,
         '1' after  20 ns,
         '0' after  40 ns,
         '1' after  60 ns,
         '0' after  80 ns,
         '1' after 100 ns,
         '0' after 120 ns,
         '1' after 140 ns,
         '0' after 160 ns,
         '1' after 200 ns;

  myB <= '0' after   0 ns,
         '0' after  20 ns,
         '1' after  40 ns,
         '1' after  60 ns,
         '0' after  80 ns,
         '0' after 100 ns,
         '1' after 120 ns,
         '1' after 140 ns,
         '0' after 160 ns;

  myC <= '0' after   0 ns,
         '0' after  20 ns,
         '0' after  40 ns,
         '0' after  60 ns,
         '1' after  80 ns,
         '1' after 100 ns,
         '1' after 120 ns,
         '1' after 140 ns,
         '0' after 160 ns;

end structural;

