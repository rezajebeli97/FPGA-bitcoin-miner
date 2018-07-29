library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library work;
use work.MyPackage.all;
use ieee.numeric_std.all;

entity Main is generic (N : unsigned := "100000");
    Port ( 
        clk : in std_logic;
        reset : in std_logic;
        a : in std_logic_vector(to_integer(N) - 1 downto 0);
        H_out : out std_logic_vector(255 downto 0)
    );
end entity;

architecture Behavioral of Main is

component Sudo_SHA256 is generic (N : unsigned := "100000");
    Port ( 
        a : in std_logic_vector(to_integer(N) - 1 downto 0);
        H_out : out std_logic_vector(255 downto 0)
    );
end component; 

type state_type is (initial_state, start , compute , finished);
signal current_state : state_type := initial_state;
signal target : std_logic_vector(255 downto 0) := x"1010101010101010101010101010101010101010101010101010101010101010";
signal hash : std_logic_vector(255 downto 0) := x"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff";
signal between_hash : std_logic_vector(255 downto 0);
signal version : std_logic_vector(31 downto 0):= x"02000000";
signal hashPrevBlock : std_logic_vector(255 downto 0):= x"17975b97c18ed1f7e255adf297599b55330edab87803c8170100000000000000";
signal hashMerkelRoot : std_logic_vector(255 downto 0);
signal time : std_logic_vector(31 downto 0):= x"358b0553";
signal difficulty : std_logic_vector(31 downto 0):= x"5350f119";
signal nonce : std_logic_vector(31 downto 0):= x"00000000";
signal block_header: std_logic_vector(639 downto 0);

begin

first_SudoSHA: Sudo_SHA256 generic map(N) port map (a , hashMerkelRoot);
main_SudoSHA: Sudo_SHA256 generic map("1010100000") port map (nonce & block_header , between_hash);
main_SudoSHA2: Sudo_SHA256 generic map("100000000") port map (between_hash , hash);


process(clk , reset)                --REG
begin
    if reset = '1' then
        current_state <= initial_state;
        
    elsif clk'event and clk = '1' then
        case current_state is
            when initial_state => 
                 block_header <= version & hashPrevBlock &hashMerkelRoot & time & difficulty & nonce;
                 current_state <= start;
                 
              when start =>
                  if (unsigned(hash) > unsigned(target)) then
                     current_state <= compute;
                  else
                     current_state <= finished;
                  end if;
              when compute =>
                 if (unsigned(hash) > unsigned(target)) then
                    current_state <= compute;
                    nonce <= std_logic_vector(unsigned(nonce) + "0001");
                 else
                    current_state <= finished;
                 end if;
                 
              when finished =>
                h_out <= hash;
                current_state <= finished;
                
              when others =>
                current_state <= initial_state;
        end case;
    end if;
end process;

end architecture;