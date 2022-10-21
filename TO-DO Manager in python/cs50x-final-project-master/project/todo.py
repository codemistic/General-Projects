import sys, datetime

args = sys.argv

# All function declartions

def print_usage():
        sys.stdout.buffer.write('''Usage :-
$ ./todo add \"todo item\"  # Add a new todo
$ ./todo ls               # Show remaining todos
$ ./todo del NUMBER       # Delete a todo
$ ./todo done NUMBER      # Complete a todo
$ ./todo help             # Show usage
$ ./todo report           # Statistics
    '''.encode('utf8'))

def read_todo(text='todo.txt'):
    try:
        f = open(text,'r')
    except FileNotFoundError:
        sys.exit(0)

    stack = []
    for l in f.readlines():
        stack.insert(0,l.strip())
    f.close()
    return stack

def write_todo(data):
    f = open('todo.txt','w')
    for d in reversed(data):
        f.write(d+'\n')
    f.close()

def write_done(data):
    date = str(datetime.date.today())
    f = open('done.txt','a')
    f.write(f"x {date} {data}"+"\n")

def console_print(data):
    sys.stdout.buffer.write(f"{data}".encode('utf8')+"\n".encode('utf8'))

#print(args)
try:
    cmd = args[1]
except IndexError:
    print_usage()
    sys.exit(0)

if cmd in ['help','add','del','done','report','ls']:
    
    if cmd == 'help':
        print_usage()

    elif cmd == 'add':
        
        try:
            open('todo.txt', 'x')
        except FileExistsError:
            pass

        data = args[2:]
        if data == []:
            console_print("Error: Missing todo string. Nothing added!.")
            sys.exit(0)

        stack = read_todo()
        for d in data:
            stack.insert(0,d)
            console_print(f'Added todo: \"{d}\"')
        write_todo(stack)

    elif cmd == 'ls':
        stack = read_todo()
        if stack == []:
            console_print('There are no pending todos!')
        else:
            l = len(stack)
            for d in stack:
                console_print(f"[{l}] {d}")
                l -= 1
            
    elif cmd == 'del':
        n = args[2:]
    
        if n == []:
            console_print('Error: Missing NUMBER for deleting todo.')
            sys.exit(0)

        stack = read_todo()
        
        for i in n:
            if len(stack) >= int(i) and int(i) > 0:
                data = stack[len(stack) - int(i)]
                stack.remove(data)
                console_print(f"Deleted todo #{i}")
            else:
                console_print(f'Error: todo #{i} does not exist. Nothing deleted.')
        write_todo(stack)
        

    elif cmd == 'done':
        n = args[2:]
    
        if n == []:
            console_print('Error: Missing NUMBER for marking todo as done.')
            sys.exit(0)

        stack = read_todo()
        
        for i in n:
            if len(stack) >= int(i) and int(i) > 0:
                data = stack[len(stack) - int(i)]
                stack.remove(data)
                console_print(f"Marked todo #{i} as done.")
                write_done(data)
            else:
                console_print(f'Error: todo #{i} does not exist.')
        write_todo(stack)
    elif cmd == 'report':
        date = str(datetime.date.today())
        pending = len(read_todo())
        complete = len(read_todo('done.txt'))
        sys.stdout.write(f"{date} Pending : {pending} Completed : {complete}"+"\n")