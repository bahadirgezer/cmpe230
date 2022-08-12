import os
def run():
    os.system("a86 p.asm")
    print("generating outpus...")
    for type in range(1, 4):
        print("type{}".format(type))
        for testcase in range(50 * type):
            if testcase % 50 == 0:
                print(testcase)
            #runs asm a86 assembly code
            os.system(f"p < inputs/type{type}/input{testcase}.txt > outputs/type{type}/myoutput{testcase}.txt")
            #compares the output with the expected output
            real_output = open("outputs/type{type}/output{testcase}.txt".format(type, testcase)).read()
            my_output = open("outputs/type{type}/myoutput{testcase}.txt".format(type, testcase)).read()
            if (real_output != my_output):
                print("type{} testcase{} failed".format(type, testcase))
                print("expected output: {}".format(real_output))
                print("my output: {}".format(my_output))

os.chdir("C:\\Documents and Settings\\bgezer\\Desktop")
run()
