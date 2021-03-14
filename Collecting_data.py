from matplotlib import pyplot as plt
import numpy as np

f=open("date.out.txt")

BubbleSort=[]
CountSort=[]
MergeSort=[]
RadixSort_baza_2=[]
RadixSort_baza_10=[]
QuickSort_pivot_random=[]
QuickSort_pivot_last_element=[]
for linie in f:
    linie=linie.split()
    if linie[0]=="BubbleSort:":
        BubbleSort.append(int(linie[1]))
    elif linie[0]=="CountSort:":
        CountSort.append(int(linie[1]))
    elif linie[0]=="MergeSort:":
        MergeSort.append(int(linie[1]))
    elif linie[0]=="RadixSort_baza_2:":
        RadixSort_baza_2.append(int(linie[1]))
    elif linie[0]=="RadixSort_baza_10:":
        RadixSort_baza_10.append(int(linie[1]))
    elif linie[0]=="QuickSort_pivot_random:":
        QuickSort_pivot_random.append(int(linie[1]))
    elif linie[0]=="QuickSort_pivot_last_element:":
       QuickSort_pivot_last_element.append(int(linie[1]))

bubble = np.mean(BubbleSort)
count = np.mean(CountSort)
radix_2 = np.mean(RadixSort_baza_2)
radix_10 = np.mean(RadixSort_baza_10)
merge = np.mean(MergeSort)
quick_random = np.mean(QuickSort_pivot_random)
quick_last = np.mean(QuickSort_pivot_last_element)

fig = plt.figure(figsize=(20, 10))
left = [1, 2, 3, 4, 5, 6, 7]


height = [bubble, count, merge, radix_2, radix_10, quick_random, quick_last]


tick_label = ['bubble', 'count', 'merge', 'radix_2', 'radix_10', 'qs_random', 'qs_last']


plt.bar(left, height, tick_label=tick_label,
        width=0.8, color=['red', 'green', 'blue'])


plt.xlabel('Axa_Algoritmi')

plt.ylabel('Axa_timpi')

plt.title('Grafic pentru: 1000 nr (nr_max=1000), elemente random')


plt.show()