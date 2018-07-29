library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

package MyPackage is 
    type array_of_stdlogicvector is array(natural range<>) of std_logic_vector(31 downto 0);
    function ro0 (input : std_logic_vector(31 downto 0)) return std_logic_vector;
    function ro1 (input : std_logic_vector(31 downto 0)) return std_logic_vector;
    function sigma0 (input : std_logic_vector(31 downto 0)) return std_logic_vector;
    function sigma1 (input : std_logic_vector(31 downto 0)) return std_logic_vector;
    function sigma2 (input : std_logic_vector(31 downto 0)) return std_logic_vector;
    function Ch (x, y, z : std_logic_vector(31 downto 0)) return std_logic_vector;
    function Maj (x, y, z : std_logic_vector(31 downto 0)) return std_logic_vector;
    function permutation (input : std_logic_vector(31 downto 0)) return std_logic_vector;
    constant K : array_of_stdlogicvector(0 to 63) := (
            x"428a2f98", x"71374491", x"b5c0fbcf", x"e9b5dba5", x"3956c25b", x"59f111f1", x"923f82a4", x"ab1c5ed5", x"d807aa98", x"12835b01", x"243185be", x"550c7dc3", x"72be5d74", x"80deb1fe", x"9bdc06a7", x"c19bf174", x"e49b69c1", x"efbe4786", x"0fc19dc6", x"240ca1cc", x"2de92c6f", x"4a7484aa", x"5cb0a9dc", x"76f988da", x"983e5152", x"a831c66d", x"b00327c8", x"bf597fc7", x"c6e00bf3", x"d5a79147", x"06ca6351", x"14292967", x"27b70a85", x"2e1b2138", x"4d2c6dfc", x"53380d13", x"650a7354", x"766a0abb", x"81c2c92e", x"92722c85", x"a2bfe8a1", x"a81a664b", x"c24b8b70", x"c76c51a3", x"d192e819", x"d6990624", x"f40e3585", x"106aa070", 
            x"19a4c116", x"1e376c08", x"2748774c", x"34b0bcb5", x"391c0cb3", x"4ed8aa4a", x"5b9cca4f", x"682e6ff3", x"748f82ee", x"78a5636f", x"84c87814", x"8cc70208", x"90befffa", x"a4506ceb", x"be49a3f7", x"c67178f2"
        );
end package;

package body MyPackage is

    function ro0 (input : std_logic_vector(31 downto 0)) return std_logic_vector is 
    variable tmp,rot17,rot14,shf12 : std_logic_vector(31 downto 0);
   begin
        rot17 := input(16 downto 0) & input (31 downto 17);
        rot14 := input(13 downto 0) & input(31 downto 14);
        shf12 := "000000000000" & input(31 downto 12);
        tmp := rot17 xor rot14 xor shf12;
        return tmp;
    end function;
    
    function ro1 (input : std_logic_vector(31 downto 0)) return std_logic_vector is 
        variable tmp,rot9,rot19,shf9 : std_logic_vector(31 downto 0);
       begin
            rot19 := input(18 downto 0) & input (31 downto 19);
            rot9 := input(8 downto 0) & input(31 downto 9);
            shf9 := "000000000" & input(31 downto 9);
            tmp := rot9 xor rot19 xor shf9;
            return tmp;
    end function;
        
    function sigma0 (input : std_logic_vector(31 downto 0)) return std_logic_vector is
        variable tmp, rot2,rot13,rot22,shf7 : std_logic_vector(31 downto 0);
        begin
            rot2 := input(1 downto 0) & input(31 downto 2);
            rot13 := input (12 downto 0) & input(31 downto 13);
            rot22 := input (21 downto 0) & input(31 downto 22);
            shf7 := "0000000" & input(31 downto 7);
            tmp := rot2 xor rot13 xor rot22 xor shf7;
            return tmp;
    end function;
    
    function sigma1 (input : std_logic_vector(31 downto 0)) return std_logic_vector is
            variable tmp, rot6,rot11,rot25 : std_logic_vector(31 downto 0);
            begin
                rot6 := input(5 downto 0) & input(31 downto 6);
                rot11 := input (10 downto 0) & input(31 downto 11);
                rot25 := input (24 downto 0) & input(31 downto 25);
                tmp := rot6 xor rot11 xor rot25;
                return tmp;
    end function;
        
    function sigma2 (input : std_logic_vector(31 downto 0)) return std_logic_vector is
                variable tmp, rot2,rot3,rot15,shf5 : std_logic_vector(31 downto 0);
                begin
                    rot2 := input(1 downto 0) & input(31 downto 2);
                    rot3 := input (2 downto 0) & input(31 downto 3);
                    rot15 := input (14 downto 0) & input(31 downto 15);
                    shf5 := "00000" & input(31 downto 5);
                    tmp := rot2 xor rot3 xor rot15 xor shf5;
                    return tmp;
    end function;
       
       
    function Ch (x, y, z : std_logic_vector(31 downto 0)) return std_logic_vector is
        variable output : std_logic_vector(31 downto 0);
        begin
            output := (x and y) xor (not y and z) xor (not x and z);
            return output;
    end function;
            
    function Maj (x, y, z : std_logic_vector(31 downto 0)) return std_logic_vector is
        variable output : std_logic_vector(31 downto 0);
        begin
            output := (x and z) xor (x and y) xor (y and z);
            return output;
    end function;
     
    function permutation (input : std_logic_vector(31 downto 0)) return std_logic_vector is 
        variable outp : std_logic_vector(31 downto 0);
        begin
            for i in 0 to 7 loop
                outp(31 - i) := input(i);
            end loop;
            outp(23 downto 16) := input(15 downto 8);
            for i in 0 to 15 loop
                outp(i) := input(31 - i);
            end loop;
            return outp;
    end function;
        
end package body;