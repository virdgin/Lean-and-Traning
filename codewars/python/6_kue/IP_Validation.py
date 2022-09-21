'''Write an algorithm that will identify valid IPv4 addresses in dot-decimal format. 
IPs should be considered valid if they consist of four octets, with values between 
0 and 255, inclusive.

'''
import ipaddress
def is_valid_IP(strng):
    try:
        ipaddress.ip_address(strng)
        return True
    except:
        return False