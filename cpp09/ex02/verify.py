import sys

input_data = sys.stdin.readlines()
if (len(input_data) < 2):
    print("Invalid input!")
    exit()
sequence = input_data[0].rstrip().split("Before: ")
sortedSequence = input_data[1].rstrip().split("After:  ")
if len(sequence) < 2 or len(sortedSequence) < 2:
    print("Invalid input!")
    exit()
sequenceSplit = sequence[1].split()
sortedSequenceSplit = sortedSequence[1].split()
sequenceSplitInt = list(map(int, sequenceSplit))
sortedSequenceSplitInt = list(map(int, sortedSequenceSplit))
if len(sequenceSplitInt) != len(sortedSequenceSplitInt):
    print("Incorrect length!")
    print(f"Set which caused the problem: {sequence}")
    exit()
sequenceSplitInt.sort()
if sequenceSplitInt != sortedSequenceSplitInt:
    print("Incorrect sort!")
    print(f"Set which caused the problem: {sequence}")
    exit()
print("Correct sort!")
