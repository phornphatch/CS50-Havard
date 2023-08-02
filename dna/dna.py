import csv
import sys

data = []
list_of_str = []

def main():

    # TODO: Check for command-line usage
    if len(sys.argv) < 3:  # need 4 command-line arguments
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # TODO: Read database file into a variable
    with open(sys.argv[1]) as file:
        file_reader = csv.DictReader(file)
        dict_from_csv = dict(list(file_reader)[0])
        list_of_column_names = list(dict_from_csv.keys())
        # print(list_of_column_names)
        list_of_str = list_of_column_names[1:]
        print(list_of_str)

        for d in file_reader:
            data.append(d)
    # for d in data:
    #     print(d["name"])
    # print(data[0])



    # TODO: Read DNA sequence file into a variable
    # once you open a text file f using open(filename), you can read its contents using f.read()
    f = open(sys.argv[2], "r")
    dna = f.read()
    # print(dna)

    # TODO: Find longest match of each STR in DNA sequence
    # len(s)
    # s[i : j] in Python takes the string s, and returns the substring with all characters from the ith character up to (but not including) the jth.
    for i 
    agat = longest_match(dna, 'AGAT')
    print(agat)
    aatg = longest_match(dna, 'AATG')
    print(aatg)
    tatc = longest_match(dna, 'TATC')
    print(tatc)

    # TODO: Check database for matching profiles
    # for d in data:
    #     if d['AGAT']

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
