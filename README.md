# Secure Auth v0
Reverse Challenge


# Description


One of NorzhNuclea's developers joined the team last quarter, specialized in authentication systems he found one he developed a few years ago with a innovative obfuscation method. Find the correct password to validate the checks.


The challenge is attached `chall.zip` that zip file contains the binary we should work on.

Let's check file information 

![Screenshot_1](https://user-images.githubusercontent.com/84577967/119221430-ae59c180-baef-11eb-9d3e-41c2e6745fd6.png)

1) We notice that the file is stripped so it kinda hard to define the real name of functions.

2) After some random things I find out that the binary file is comparing the string you give with `c-n|TD^zJFp|I'q\"VCj7.mNj4`, it maybe a kind of XOR I tried to find 
  the key but I failed (I used the script below)
  
  ```python
  import string

def xor(msg, key):
    o = ''
    for i in range(len(msg)):
        o += chr(ord(msg[i]) ^ ord(key[i % len(key)]))
    return o
  
with open('msg.enc', 'r') as f:
    msg = ''.join(f.readlines())
    print(len(msg))
    
# We know this part that exists in the flag
part_of_msg = 'NORZH{'

for i in range(len(msg)):
    candidate = xor(msg[i:i+len(part_of_msg)], part_of_msg)
    if candidate.isalnum():
        print(candidate)
  ```

![Screenshot_2](https://user-images.githubusercontent.com/84577967/119221431-af8aee80-baef-11eb-915e-5e3a5159fce4.png)

3) So I had to try something else with IDA and try to decompile the binary to a C file and I felt like the key is `f4|<eN3w$`, but I was wrong :( !

![Screenshot_3](https://user-images.githubusercontent.com/84577967/119221432-b0238500-baef-11eb-8c2a-c5fa91471b90.png)

```python
import string

def xor(msg, key):
    o = ''
    for i in range(len(msg)):
        o += chr(ord(msg[i]) ^ ord(key[i % len(key)]))
    return o

with open('msg.enc', 'r') as f:
    msg = ''.join(f.readlines())

key = 'f4|<eN3w$'

print(xor(msg,key))
```
