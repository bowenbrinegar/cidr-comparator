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

1. Parses bit count on first IP & Concatenates relavent amount into single integer
    1. 127.0.0.1/1 => 1
    1. 127.0.0.1/8 => 127
    1. 127.0.0.1/16 => 1270
    1. 127.0.0.1/24 => 12700
    1. 127.0.0.1/32 => 127001
    
1. Converts Concatenated Integer into a Singly Linked List containing the binary for each digit
    1. 1270001 => 11111000000011001 (note program operates on flipped order)
    1. 1270 => 10011110110
    1. 127 => 1111111
    
1. Converts Linked List of Binary to String
    1. 10011110110 => [HEAD] => 1 => 0 => 0 => 1 => 1 => 1 => 1 => 0 => 1 => 1 => 0 => (null) => "10011110110"
1. Compares each string

### Use Cases

- In Cloud services you can use CIDR validation for resource permissioning
- In a custom environment, you can validate ingress traffic against whitelisted ip signatures


### How it's done in C#

    IPNetwork ipnetwork = IPNetwork.Parse("192.168.168.100/24");
    
    IPAddress ipaddress = IPAddress.Parse("192.168.168.200");
    IPAddress ipaddress2 = IPAddress.Parse("192.168.0.200");
    
    bool contains1 = IPNetwork.Contains(ipnetwork, ipaddress);
    bool contains2 = IPNetwork.Contains(ipnetwork, ipaddress2);

