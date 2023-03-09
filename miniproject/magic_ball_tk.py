from random import choice
from tkinter import Frame,Label,Tk, Entry

answers = ["во дурак", "не смей!", "как тебе тоолько это в голову пришло???", "не, ну тут я бессилен", "а в этом что-то есть", "мне нравится, куда ты клонишь :)", "да ты гений!",
           "да! да! да!", "ну попробуй...", "если ты так уверен...", "может, и не облажаешься", "дерзай!...наверное", "твое право", "я в этом не участввую", "отстань, не хочу отвечать", "...."]


def valid(a):
    if a == 'да':
        return True
    else:
        print('Возвращайся когда надумаешь...')
        return False


def start():
   # print('Привет я Магический Шар!')
    #print('Я знаю ответы на все твои вопросы...')
    #name = input('Как тебя зовут? ').capitalize()
    #print('Привет,', name, '!')
    flag = valid(input('Хочешь задать вопрос? ').lower())
    while flag:
        print('Задавай вопрос:')
        text = input()
        print(choice(answers))
        flag = valid(input('Eщё вопрос? ').lower())


window = Tk()
window.title()
window.geometry('500x300')
frame =Frame(window)
entry = Entry()
frame.pack(expand = True)
_text = f'Привет я Магический Шар!\nЯ знаю ответы на все твои вопросы...\nКак тебя зовут?'
main_lbl = Label(
    frame,
    text = _text,
    font = 'Arial 15',
)
main_lbl.grid()
entry.pack() 
#start()
window.mainloop()