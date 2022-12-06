def check(c, diz):
    for k,v in diz.items():
        if c == v:
            return True
    return False

def lettura(nome):
    s = open(nome, "r").read()

    return s

def main():
    diz = {"{":"}", "[":"]", "(":")"}
    stack = []
    
    s = "{ciao[()]\n{[]}"

    for car in lettura("file.txt"):
        if car in diz:
            stack.append(car)
        ok = check(car, diz)
        if ok:
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