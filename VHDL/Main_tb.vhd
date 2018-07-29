library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity Main_tb is
end entity;

architecture testbench of Main_tb is
  
   component Main is generic (N : unsigned);
    Port ( 
        clk : in std_logic;
        reset : in std_logic;
        a : in std_logic_vector(to_integer(N) - 1 downto 0);
        H_out : out std_logic_vector(255 downto 0)
    );
  end component;
    
  signal a : std_logic_vector(31 DOWNTO 0) := x"61626364";
  signal H_out : std_logic_vector(255 DOWNTO 0);
  signal clk ,reset : std_logic;

begin

MyBitCoinMiner : Main generic map ("100000") port map (clk ,reset ,a ,H_out);

ClockGen: process
    begin
      while true loop
          clk <= '0';
            wait for 50 ns;
            clk <= '1';
            wait for 50 ns;
        end loop;
        wait;
    end process ;

really: process
begin
  reset <= '1';
  
  wait for 100 ns;

  reset <= '0';
  wait for 100 ns;
  wait;
end process ; 

end architecture ; 
