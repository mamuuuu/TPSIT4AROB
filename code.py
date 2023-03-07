import queue

coda = queue.Queue()

#enqueue -> put
#dequeue -> get

coda.put(5)
coda.put(13)
coda.put(7)

print(coda.get())#legge l'elemento e lo cancella
print(coda.queue)