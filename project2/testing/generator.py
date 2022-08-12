import random
from turtle import left
digits = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F']
operators = ['+', '*', '/', '^', '&', '|']

def generate_hex():
    hex = ""
    for i in range(random.randint(1, 4)):
        hex = hex + random.choice(digits)
    return hex

def hex_xor(hex1, hex2):
    int1 = int(hex1.lower(), 16)
    int2 = int(hex2.lower(), 16)
    return hex(int1 ^ int2)[2:].upper()

def hex_or(hex1, hex2):
    int1 = int(hex1.lower(), 16)
    int2 = int(hex2.lower(), 16)
    return hex(int1 | int2)[2:].upper()    

def hex_and(hex1, hex2):
    int1 = int(hex1.lower(), 16)
    int2 = int(hex2.lower(), 16)
    return hex(int1 & int2)[2:].upper()

def hex_addition(hex1, hex2):
    int1 = int(hex1.lower(), 16)
    int2 = int(hex2.lower(), 16)
    return hex(int1 + int2)[2:].upper()

def hex_multiplication(hex1, hex2):
    int1 = int(hex1.lower(), 16)
    int2 = int(hex2.lower(), 16)
    return hex(int1 * int2)[2:].upper()

def hex_division(hex1, hex2):
    int1 = int(hex1.lower(), 16)
    int2 = int(hex2.lower(), 16)
    return hex(int1 // int2)[2:].upper()

def is_hex(hex):
    for character in hex:
        if character not in digits:
            return False
    return True

class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


#recursively generate a tree data structure
def generate_tree(max_depth):
    if max_depth == 0:
        return None
    node_type = random.randint(0,2)
    if (node_type == 0):
        node = Node(generate_hex())
        return node
    elif (node_type == 1):
        node = Node(random.choice(operators))
        node.left = generate_tree(max_depth - 1)
        node.right = generate_tree(max_depth - 1)
        return node
    else:
        node = Node(random.choice(operators))
        node.left = Node(generate_hex())
        node.right = Node(generate_hex())
        return node

#print binary tree to the console
def convert_to_postfix(root, postfix):
    if root is None:
        return
    convert_to_postfix(root.left, postfix)
    convert_to_postfix(root.right, postfix)
    #print(root.value)
    postfix.append(root.value)

def evaluate_postfix(postfix_array):
    stack = []
    for i in range(len(postfix_array)):
        if is_hex(postfix_array[i]):
            stack.append(postfix_array[i])
        elif postfix_array[i] in operators: 
            if len(stack) < 2:
                stack.append(postfix_array[i])
            else:
                op2 = stack.pop()
                op1 = stack.pop()
                if postfix_array[i] == '+':
                    result = hex_addition(op1, op2)
                elif postfix_array[i] == '*':
                    result = hex_multiplication(op1, op2)
                elif postfix_array[i] == '/':
                    if op2 == '0':
                        print('Division by zero')
                        return 
                    result = hex_division(op1, op2)
                elif postfix_array[i] == '^':
                    result = hex_xor(op1, op2)
                elif postfix_array[i] == '&':
                    result = hex_and(op1, op2)
                elif postfix_array[i] == '|':
                    result = hex_or(op1, op2)
                if (len(result) > 4):
                    print("16 bit overflow")
                    return
                stack.append(result)
        else:
            print("Invalid operator")
            return
    return stack.pop()

def array_to_string(array):
    string = ""
    for i in range(len(array)):
        string = string + array[i] + " "
    string = string.strip()
    string = string + '\n'
    return string

# for type in range(1, 4):
#     for testcase in range(50 * type):
#         while(True):
#             output = None
#             root = generate_tree(50*(type**3))
#             postfix_array = []
#             convert_to_postfix(root, postfix_array)
#             while (len(postfix_array) < 10 * (type ** 2)):
#                 root = generate_tree(50)
#                 postfix_array = []
#                 convert_to_postfix(root, postfix_array)
#             try:
#                 output = evaluate_postfix(postfix_array)
#                 if output is not None:
#                     break
#             except:
#                 continue
#         file = open("testcases/inputs/input{}.txt".format(type * testcase), 'w')
#         file.write(array_to_string(postfix_array))
#         file.close()
#         file = open("testcases/outputs/output{}.txt".format(type * testcase), 'w')
#         file.write(output)
#         file.close()
#         # print()
#         # print("Testcase #" + str(testcase + 1))
#         # print(postfix_array)
#         # print(output)
#print(evaluate_postfix(['57', '82', '+', '32', '^', '3', 'FA', '8B', '&', '|', '*']))
#print(evaluate_postfix(['1', '1', '+', '2', '^']))

#print(evaluate_postfix(['B1', '3', '&', 'C', '/']))


for testcase in range(1, 100):
    while(True):
        output = None
        root = generate_tree(testcase*5)
        postfix_array = []
        convert_to_postfix(root, postfix_array)
        while (len(postfix_array) < testcase):
            root = generate_tree(testcase*5)
            postfix_array = []
            convert_to_postfix(root, postfix_array)
        try:
            output = evaluate_postfix(postfix_array)
            if output is not None:
                break
        except:
            continue
    file = open("testcases/inputs/input{}.txt".format(testcase), 'w')
    file.write(array_to_string(postfix_array))
    file.close()
    file = open("testcases/outputs/output{}.txt".format(testcase), 'w')
    file.write(output)
    file.close()
