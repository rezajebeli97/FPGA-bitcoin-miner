library ieee ;
use ieee.std_logic_1164.all ;
use ieee.numeric_std.all ;
library work;
use work.MyPackage.all;

entity Step3 is
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
  ) ;
end entity;

architecture arch of Step3 is
begin
    p1 : process( W, initial_H0 ,  initial_H1 , initial_H2 , initial_H3 , initial_H4 , initial_H5 , initial_H6 , initial_H7)
        variable H : array_of_stdlogicvector(0 to 7);
        variable a, b, c, d, e, f, g, eh, T1, T2 : std_logic_vector(31 downto 0);
        begin
            H(0) := initial_H0;
            H(1) := initial_H1;
            H(2) := initial_H2;
            H(3) := initial_H3;
            H(4) := initial_H4;
            H(5) := initial_H5;
            H(6) := initial_H6;
            H(7) := initial_H7;
            
            a := H(0);
            b := H(1);
            c := H(2);
            d := H(3);
            e := H(4);
            f := H(5);
            g := H(6);
            eh := H(7);
                            
            for i in 0 to 63 loop
                
                
                T2 := std_logic_vector(unsigned(eh) + unsigned(Sigma1(e)) + unsigned(Ch(e, f, g)) + unsigned(K(i)) + unsigned(W(i)));
                T1 := std_logic_vector(unsigned(sigma0(a)) + unsigned(Maj(a, b, c)) + unsigned(sigma2(std_logic_vector(unsigned(c) + unsigned(d)))));
                eh := g;
                f := e;
                d := c;
                b := a;
                g := f;
                e := std_logic_vector(unsigned(d) + unsigned(T1));
                c := b;
                a := std_logic_vector(unsigned(T1) + unsigned(T1) + unsigned(T1) - unsigned(T2));

                
            end loop;
            H(0) := std_logic_vector(unsigned(a) + unsigned(H(0)));
                            H(1) := std_logic_vector(unsigned(b) + unsigned(H(1)));
                            H(2) := std_logic_vector(unsigned(c) + unsigned(H(2)));
                            H(3) := std_logic_vector(unsigned(d) + unsigned(H(3)));
                            H(4) := std_logic_vector(unsigned(e) + unsigned(H(4)));
                            H(5) := std_logic_vector(unsigned(f) + unsigned(H(5)));
                            H(6) := std_logic_vector(unsigned(g) + unsigned(H(6)));
                            H(7) := std_logic_vector(unsigned(eh) + unsigned(H(7)));
                            
            H_out0 <= H(0);
            H_out1 <= H(1);
            H_out2 <= H(2);
            H_out3 <= H(3);
            H_out4 <= H(4);
            H_out5 <= H(5);
            H_out6 <= H(6);
            H_out7 <= H(7);
        end process ; -- p1
end architecture ;