def check(c, diz):
    for k,v in diz.items():
        if c == v:
            return True
    return False

def lettura(nome):
    with open(nome,"r") as file:
        s = file.read()

    return s

def main():
    diz = {"{":"}", "[":"]", "(":")"}
    stack = []
    
    for car in lettura("file.txt"):
        if car in diz:
            stack.append(car)
        else:
            if check(car, diz):
                if car == diz[stack[-1]]:
                    stack.pop()
                else:
                    print("Errore")
                    exit()

    if (len(stack)!=0):
        print("Errore")
    else:
        print("Corretto")

if __name__ == "__main__":
    main()