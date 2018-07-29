library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library work;
use work.MyPackage.all;
use ieee.numeric_std.all;

entity Step2 is
    Port (
        input : in std_logic_vector(511 downto 0);
        output : out array_of_stdlogicvector(0 to 63)
     );
end entity;

architecture Behavioral of Step2 is
begin
    process (input)
        variable w : array_of_stdlogicvector(0 to 63);
        begin
            for i in 0 to 15 loop
                w(i) := input((511 - i*32) downto (511 - i*32 - 31));
            end loop;
            for i in 16 to 63 loop
                w(i) := std_logic_vector(unsigned(ro1(w(i-1))) + unsigned( w(i-6)) + unsigned(ro0(w(i-12))) + unsigned(w(i-15)));
            end loop;
            for i in 0 to 63 loop 
                w(i) := permutation(w(i));
            end loop;
            output <= w;
    end process;
        
end architecture;