def get_input():
    """
    get input from user
    """
    input_str = input("Enter elements to be sorted: ")
    try:
        elements = [int(e) for e in input_str.split()] #make a list of integers from input string
    except ValueError:
        print("Please enter a list of integers only, seperated by a space!!")
    return elements

def insertion_sort(thelist):
    """
    Insertion sort algorithm
    """
    if len(thelist) == 0:
        print("Empty list!!")

    elif len(thelist) == 1:
        print("Only one element!!")

    else:
        for index in range(1, len(thelist)):
            key = thelist[index]
            position = index - 1
            while position >= 0 and thelist[position] >= key:
                thelist[position + 1] = thelist[position]
                position = position - 1
            thelist[position + 1] = key

if __name__ == '__main__':
    input_list = get_input()
    insertion_sort(input_list)
    print(*input_list, sep = ", ")
