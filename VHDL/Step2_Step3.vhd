library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library work;
use work.MyPackage.all;

entity Step2_Step3 is
    Port ( 
        input : in std_logic_vector(511 downto 0);
        initial_H0 : in std_logic_vector(31 downto 0);
        initial_H1 : in std_logic_vector(31 downto 0);
        initial_H2 : in std_logic_vector(31 downto 0);
        initial_H3 : in std_logic_vector(31 downto 0);
        initial_H4 : in std_logic_vector(31 downto 0);
        initial_H5 : in std_logic_vector(31 downto 0);
        initial_H6 : in std_logic_vector(31 downto 0);
        initial_H7 : in std_logic_vector(31 downto 0);
        H_out0 : out std_logic_vector(31 downto 0);
        H_out1 : out std_logic_vector(31 downto 0);
        H_out2 : out std_logic_vector(31 downto 0);
        H_out3 : out std_logic_vector(31 downto 0);
        H_out4 : out std_logic_vector(31 downto 0);
        H_out5 : out std_logic_vector(31 downto 0);
        H_out6 : out std_logic_vector(31 downto 0);
        H_out7 : out std_logic_vector(31 downto 0)
    );
end entity;

architecture Behavioral of Step2_Step3 is
component Step2 is
    Port (
        input : in std_logic_vector(511 downto 0);
        output : out array_of_stdlogicvector(0 to 63)
     );
end component;
component Step3 is
  port (
    W : in array_of_stdlogicvector(0 to 63);
    initial_H0 : in std_logic_vector(31 downto 0);
    initial_H1 : in std_logic_vector(31 downto 0);
    initial_H2 : in std_logic_vector(31 downto 0);
    initial_H3 : in std_logic_vector(31 downto 0);
    initial_H4 : in std_logic_vector(31 downto 0);
    initial_H5 : in std_logic_vector(31 downto 0);
    initial_H6 : in std_logic_vector(31 downto 0);
    initial_H7 : in std_logic_vector(31 downto 0);
    H_out0 : out std_logic_vector(31 downto 0);
    H_out1 : out std_logic_vector(31 downto 0);
    H_out2 : out std_logic_vector(31 downto 0);
    H_out3 : out std_logic_vector(31 downto 0);
    H_out4 : out std_logic_vector(31 downto 0);
    H_out5 : out std_logic_vector(31 downto 0);
    H_out6 : out std_logic_vector(31 downto 0);
    H_out7 : out std_logic_vector(31 downto 0)
  );
end component;
signal W : array_of_stdlogicvector(0 to 63);
begin
s2: Step2 port map (input , W);
s3: Step3 port map ( W  ,initial_H0 ,initial_H1 , initial_H2 , initial_H3 , initial_H4 , initial_H5 , initial_H6 , initial_H7 
    , H_out0 , H_out1 , H_out2 ,H_out3 ,H_out4 ,H_out5 ,H_out6 , H_out7);
end architecture;
