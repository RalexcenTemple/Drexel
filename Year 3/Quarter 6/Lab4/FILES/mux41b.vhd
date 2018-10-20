--
--  File: mux.vhd
--  4:1 Multiplexer
--
Library IEEE;
use IEEE.std_logic_1164.all;
--Entity Declaration
entity mux41 is
        port(I0,I1,I2,I3 : in STD_LOGIC;
                 Sel : in STD_LOGIC_vector(1 downto 0);
                 Z : out STD_LOGIC);
end mux41;

--Architecture Definition
architecture behavioral of mux41 is
begin
  with Sel select
     Z <= I0 after  1 ns when "00",
          I1 after  1 ns when "01",
          I2 after  1 ns when "10",
          I3 after  1 ns when "11",
          'X' after 1 ns when others;
end behavioral;
