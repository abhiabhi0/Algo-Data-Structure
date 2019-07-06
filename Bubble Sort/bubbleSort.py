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

def bubble_sort(thelist):
    """
    Bubble Sort algorithm
    """
    if len(thelist) == 0:
        print("Empty list!!")

    elif len(thelist) == 1:
        print("Only one element!!")

    else:
        for i in range(len(thelist) - 1):

            for j in range(len(thelist) - i - 1):
                if thelist[j] > thelist[j+1]: #if element is greater than from next element
                    thelist[j], thelist[j+1] = thelist[j+1], thelist[j] #swapping

if __name__ == '__main__':
    input_list = get_input()
    bubble_sort(input_list)
    print(*input_list, sep = ", ")
