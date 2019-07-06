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

def max_heapify(thelist, lst_size: int, idx: int):
    """
    Building maximum heap at index passed as argument
    """
    largest = idx
    left_child = 2 * idx + 1
    right_child = 2 * idx + 2

    #comparing left child and largest
    if left_child < lst_size and thelist[left_child] > thelist[largest]:
        largest = left_child

    #comparing right child and largest
    if right_child < lst_size and thelist[right_child] > thelist[largest]:
        largest = right_child

    if largest != idx: #if largest is changed
        thelist[idx], thelist[largest] = thelist[largest], thelist[idx] #swapping
        max_heapify(thelist, lst_size, largest)

def build_max_heap(thelist, lst_size: int):
    """
    Building maximum heap from the list passed as argument
    """
    for curr_idx in range(lst_size // 2 - 1, -1, -1): #loop from higher index to lower index
        max_heapify(thelist, lst_size, curr_idx)

def heap_sort(thelist):
    """
    Heap sort Algorithm
    """
    if len(thelist) == 0:
        print("Empty list!!")

    elif len(thelist) == 1:
        print("Only one element!!")

    else:
        build_max_heap(thelist, len(thelist))

        for curr_idx in range(len(thelist) -1, 0, -1): #loop from higher index to lower index
            thelist[curr_idx], thelist[0] = thelist[0], thelist[curr_idx] #swapping
            max_heapify(thelist, curr_idx, 0)

if __name__ == '__main__':
    input_list = get_input()
    heap_sort(input_list)
    print(*input_list, sep = ", ")
