library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.numeric_std.all;

entity pars is generic(N : unsigned := "100000");
    Port (a : in std_logic_vector(to_integer(N) - 1 downto 0);
          b : out std_logic_vector(to_integer(N) + 64 + 512 - ((to_integer(N) + 64) mod 512) - 1 downto 0)
          );
end entity;

architecture Behavioral of pars is
begin
p1 : process(a)
variable n_integer : integer := to_integer(N);
variable size : integer := n_integer + 64 + 512 - ((n_integer + 64) mod 512);
begin
    b(size - 1 downto size - n_integer) <= a;
    b(size - n_integer - 1 ) <= '1';
    b(size - n_integer - 2 downto 64) <= (others => '0');
    b(N'high downto N'low) <= std_logic_vector(N);
    b(64 downto N'high + 1) <= (others => '0');

end process ;

end architecture;