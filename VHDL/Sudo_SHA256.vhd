library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.numeric_std.all;
library work;
use work.MyPackage.all;

entity Sudo_SHA256 is generic (N : unsigned := "100000");
    Port ( 
        a : in std_logic_vector(to_integer(N) - 1 downto 0);
        H_out : out std_logic_vector(255 downto 0)
    );
end entity;

architecture Structural of Sudo_SHA256 is

component pars is generic(N : unsigned := "100000");
    Port (
          a : in std_logic_vector(to_integer(N) - 1 downto 0);
          b : out std_logic_vector(to_integer(N) + 64 + 512 - ((to_integer(N) + 64) mod 512) - 1 downto 0)
          );
end component;

component Step2_Step3 is
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
end component;

signal M : std_logic_vector(to_integer(N) + 64 + 512 - ((to_integer(N) + 64) mod 512) - 1 downto 0);
signal initial_H0 : std_logic_vector(31 downto 0) := x"6a09e667";
signal initial_H1 : std_logic_vector(31 downto 0) := x"bb67ae85";
signal initial_H2 : std_logic_vector(31 downto 0) := x"3c6ef372";
signal initial_H3 : std_logic_vector(31 downto 0) := x"a54ff53a";
signal initial_H4 : std_logic_vector(31 downto 0) := x"510e527f";
signal initial_H5 : std_logic_vector(31 downto 0) := x"9b05688c";
signal initial_H6 : std_logic_vector(31 downto 0) := x"1f83d9ab";
signal initial_H7 : std_logic_vector(31 downto 0) := x"5be0cd19";

signal H0 : array_of_stdlogicvector(((to_integer(N) + 64 + 512 - ((to_integer(N) + 64) mod 512)) / 512) - 1 downto 0);
signal H1 : array_of_stdlogicvector(((to_integer(N) + 64 + 512 - ((to_integer(N) + 64) mod 512)) / 512) - 1 downto 0);
signal H2 : array_of_stdlogicvector(((to_integer(N) + 64 + 512 - ((to_integer(N) + 64) mod 512)) / 512) - 1 downto 0);
signal H3 : array_of_stdlogicvector(((to_integer(N) + 64 + 512 - ((to_integer(N) + 64) mod 512)) / 512) - 1 downto 0);
signal H4 : array_of_stdlogicvector(((to_integer(N) + 64 + 512 - ((to_integer(N) + 64) mod 512)) / 512) - 1 downto 0);
signal H5 : array_of_stdlogicvector(((to_integer(N) + 64 + 512 - ((to_integer(N) + 64) mod 512)) / 512) - 1 downto 0);
signal H6 : array_of_stdlogicvector(((to_integer(N) + 64 + 512 - ((to_integer(N) + 64) mod 512)) / 512) - 1 downto 0);
signal H7 : array_of_stdlogicvector(((to_integer(N) + 64 + 512 - ((to_integer(N) + 64) mod 512)) / 512) - 1 downto 0);

begin
parsModule: pars generic map(N) port map(a , M);

foreach_Block: for i in ((to_integer(N) + 64 + 512 - ((to_integer(N) + 64) mod 512)) / 512) - 1 downto 0 generate

    if_first_s3: if i=(((to_integer(N) + 64 + 512 - ((to_integer(N) + 64) mod 512)) / 512) - 1) generate
        first_s3: Step2_Step3 port map( M( i*512 + 511 downto i*512 ), initial_H0 , initial_H1 , initial_H2 , initial_H3 , initial_H4 , initial_H5 , initial_H6 , initial_H7 ,H0(i) ,H1(i) ,H2(i) ,H3(i) ,H4(i) ,H5(i) ,H6(i) ,H7(i) );
    end generate;
    if_not_first_s3: if i < (((to_integer(N) + 64 + 512 - ((to_integer(N) + 64) mod 512)) / 512) - 1) generate 
        not_first_s3: Step2_Step3 port map( M( i*512 + 511 downto i*512 ) ,H0(i+1) ,H1(i+1) ,H2(i+1) ,H3(i+1) ,H4(i+1) ,H5(i+1) ,H6(i+1) ,H7(i+1) ,H0(i) ,H1(i) ,H2(i) ,H3(i) ,H4(i) ,H5(i) ,H6(i) ,H7(i)  );
    end generate;

end generate;
    H_out <= H0(0) & H1(0) & H2(0) & H3(0) & H4(0) & H5(0) & H6(0) & H7(0);
   
end architecture;