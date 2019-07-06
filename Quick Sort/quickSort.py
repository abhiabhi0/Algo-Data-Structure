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

def partition(thelist, start_idx: int, end_idx: int):
    """
    partition list according to pivot and return index of pivot
    """
    pivot = thelist[end_idx] #select last element as the pivot
    idx = start_idx - 1

    for curr_idx in range(start_idx, end_idx):
        if thelist[curr_idx] <= pivot:
            idx += 1 #increment
            thelist[idx], thelist[curr_idx] = thelist[curr_idx], thelist[idx] #swapping

    thelist[idx+1], thelist[end_idx] = thelist[end_idx], thelist[idx+1] #swapping
    return idx+1 #returning pivot index

def quick_sort(thelist, start_idx: int, end_idx: int):
    """
    Quick Sort Algorithm
    """
    if len(thelist) == 0:
        print("Empty list!!")

    elif len(thelist) == 1:
        print("Only one element!!")

    elif start_idx < end_idx:
        pivot_idx = partition(thelist, start_idx, end_idx) #get pivot index
        quick_sort(thelist, start_idx, pivot_idx - 1) #apply algorithm for smaller list
        quick_sort(thelist, pivot_idx + 1, end_idx) #apply algorithm for smaller list

if __name__ == '__main__':
    input_list = get_input()
    quick_sort(input_list, 0, len(input_list) - 1)
    print(*input_list, sep = ", ")
