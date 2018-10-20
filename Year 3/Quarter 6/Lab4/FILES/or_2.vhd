--
--  File: or2.vhd
--  2 input OR gate
--
library IEEE;
use IEEE.std_logic_1164.all;

entity or_2 is
    port(a, b: in STD_LOGIC;
         c : out STD_LOGIC);
end or_2;

architecture behavioral of or_2 is
begin
  c <= (a or b) after 1 ns;
end behavioral;


