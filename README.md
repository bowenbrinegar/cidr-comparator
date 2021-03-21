### CIDR IP Comparator

- Intake: IP Address ("n.n.n.n/n")
- Output: Validation to defined IP

### Compile

- gcc main.c

### Run

- ./a.out "n.n.n.n/n" "n.n.n.n"

### Logic

1. Intakes two IP Addresses through command arguments;

1. Validates each IP to predefined regex signature

1. Parses bit count on first IP & Concatenates relevant amount into single integer
    1. 127.0.0.1/1 => 1
    1. 127.0.0.1/8 => 127
    1. 127.0.0.1/16 => 1270
    1. 127.0.0.1/24 => 12700
    1. 127.0.0.1/32 => 127001
    
1. Converts Concatenated Integer into binary in string form
    1. 1270001 => 11111000000011001 (note program operates on flipped order)
    1. 1270 => 10011110110
    1. 127 => 1111111
    
1. Compares each string

### Alternate Solution

1. Logic in this repo can be simplified
    1. Assumptions is n.n.n.n == [1-8bits].[1-8bits].[1-8bits].[1-8bits] == [group a].[group b].[group c].[group d]
    1. Intaking "/1" | "/8" | "16" | "24" | "32" you can either convert group(s) [a-d] or subgroup of [a] in case "/1"
        1. "/1" takes the 1st bit of [group a]
        1. "/8" takes all of [group a]
        1. "/16" takes all of [group a] and [group b] (regardless of the bit count within each group)
        1. Eccetera.
    1. Without converting to binary, you could compare the two serialized integers via strcmp
    1. Alternatively, you could convert the subcharacters to their binary signatures of the 
    serialized integer grouping and compare those through a loop. (flag inequality if exists; return flag;)

### Use Cases

- In Cloud services you can use CIDR validation for resource permissioning
- In a custom environment, you can validate ingress traffic against whitelisted ip signatures


### How it's done in C#

    IPNetwork ipnetwork = IPNetwork.Parse("192.168.168.100/24");
    
    IPAddress ipaddress = IPAddress.Parse("192.168.168.200");
    IPAddress ipaddress2 = IPAddress.Parse("192.168.0.200");
    
    bool contains1 = IPNetwork.Contains(ipnetwork, ipaddress);
    bool contains2 = IPNetwork.Contains(ipnetwork, ipaddress2);

