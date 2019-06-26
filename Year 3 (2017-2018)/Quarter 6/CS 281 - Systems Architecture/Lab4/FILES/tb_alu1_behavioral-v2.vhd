-- TEST BENCH 1-BIT ALU BEHAVIORAL

library IEEE;
use IEEE.std_logic_1164.all;

entity tb_alu1b is
end entity;

architecture behavioral of tb_alu1b is

component alu1b
 port(
  a,b,CarryIn : in STD_LOGIC;
      Operation : in STD_LOGIC_vector (1 downto 0);
         Result, CarryOut : out STD_LOGIC
  );
end component;

  signal myA, myB, myC, myRes, myC_out : STD_LOGIC := '1';
  signal myOp : STD_LOGIC_vector (1 downto 0) := "11";

begin

   TB: alu1b
    port map (
    a => myA,
    b => myB,
    CarryIn => myC,
    Operation => myOp,
    Result => myRes,
    CarryOut => myC_out
    );
   
   process
   begin
   	myA <= not myA;
   	wait for 10 ns;
   end process;

   process
   begin
   	myB <= not myB;
   	wait for 20 ns;
   end process;

   process
   begin
   	myC <= not myC;
   	wait for 40 ns;
   end process;

   process
   begin
   	myOp(0) <= not myOp(0);
   	wait for 80 ns;
   end process;

   process
   begin
   	myOp(1) <= not myOp(1);
   	wait for 160 ns;
   end process;

end behavioral;

