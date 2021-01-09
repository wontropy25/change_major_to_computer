from tkinter import *
import tkinter.ttk as ttk

root = Tk()
root.title("다항함수 적분계산기")
root.resizable(False, False) 

# 구간 프레임
frame_interval = LabelFrame(root, text="적분할 구간 설정")
frame_interval.grid(row=0, column=0, sticky=W, padx=5, pady=5, ipady=5)

# 구간 시작
label_text = Label(frame_interval, text="구간 시작값", width=10)
label_text.pack(side="left", padx=5, pady=5)
start_entry = Entry(frame_interval, width=6)
start_entry.insert(0, 0)
start_entry.pack(side="left", padx=5)

# 구간 끝
label_text = Label(frame_interval, text="구간 끝값", width=10)
label_text.pack(side="left", padx=5, pady=5)
end_entry = Entry(frame_interval, width=6)
end_entry.insert(0, 0)
end_entry.pack(side="left", padx=5)

# 계수 프레임
frame_coefficient = LabelFrame(root, text="다항함수 계수 설정")
frame_coefficient.grid(row=1, column=0,padx=5, pady=5, ipady=5)

# 4차항 계수
label_text = Label(frame_coefficient, text="4차항 계수", width=10)
label_text.pack(side="left", padx=5, pady=5)
num4_entry = Entry(frame_coefficient, width=6)
num4_entry.insert(0, 0)
num4_entry.pack(side="left", padx=5)

# 3차항 계수
label_text = Label(frame_coefficient, text="3차항 계수", width=10)
label_text.pack(side="left", padx=5, pady=5)
num3_entry = Entry(frame_coefficient, width=6)
num3_entry.insert(0, 0)
num3_entry.pack(side="left", padx=5)

# 2차항 계수
label_text = Label(frame_coefficient, text="2차항 계수", width=10)
label_text.pack(side="left", padx=5, pady=5)
num2_entry = Entry(frame_coefficient, width=6)
num2_entry.insert(0, 0)
num2_entry.pack(side="left", padx=5)

# 1차항 계수
label_text = Label(frame_coefficient, text="1차항 계수", width=10)
label_text.pack(side="left", padx=5, pady=5)
num1_entry = Entry(frame_coefficient, width=6)
num1_entry.insert(0, 0)
num1_entry.pack(side="left", padx=5)

# 상수
label_text = Label(frame_coefficient, text="상수항 값", width=10)
label_text.pack(side="left", padx=5, pady=5)
num0_entry = Entry(frame_coefficient, width=6)
num0_entry.insert(0, 0)
num0_entry.pack(side="left", padx=5)

# 함수식 출력
txt = Text(root, height=5)
txt.grid(row=2, column=0, ipadx=130)

# 적분결과 출력
frame_integral = LabelFrame(root, text="적분값 계산하기")
frame_integral.grid(row=3, column=0, sticky=W, padx=5, pady=5, ipady=5)
result = Text(frame_integral, width=99, height=3)
result.pack(side="right", padx=10)

def function_test():
    start = start_entry.get()
    end = end_entry.get()
    num4 = num4_entry.get()
    num3 = num3_entry.get()
    num2 = num2_entry.get()
    num1 = num1_entry.get()
    num0 = num0_entry.get()

    txt.delete("1.0", END) 
    txt.insert(END, "int _{"+str(start)+"} ^{"+str(end)+"} {("+str(num4)+"x^{4}+ "+str(num3)+"x^{3}+ "\
        +str(num2)+"x^{2}+ "+str(num1)+"x^{1}+ "+str(num0)+")dx}")

def integral():
    result.delete("1.0", END)

    start = start_entry.get()
    end = end_entry.get()
    num4 = num4_entry.get()
    num3 = num3_entry.get()
    num2 = num2_entry.get()
    num1 = num1_entry.get()
    num0 = num0_entry.get()

    result_integral = ((float(num4)/5.0)*(float(end)**5 - float(start)**5)) + \
        ((float(num3)/4.0)*(float(end)**4 - float(start)**4)) + \
        ((float(num2)/3.0)*(float(end)**3 - float(start)**3)) + \
        ((float(num1)/2.0)*(float(end)**2 - float(start)**2)) + \
        ((float(num0))*(float(end) - float(start)))

    result.insert(END, result_integral)

def reset():
    start_entry.delete(0, END)
    end_entry.delete(0, END)
    num4_entry.delete(0, END)
    num3_entry.delete(0, END)
    num2_entry.delete(0, END)
    num1_entry.delete(0, END)
    num0_entry.delete(0, END)
    start_entry.insert(0, 0)
    end_entry.insert(0, 0)
    num4_entry.insert(0, 0)
    num3_entry.insert(0, 0)
    num2_entry.insert(0, 0)
    num1_entry.insert(0, 0)
    num0_entry.insert(0, 0)
    txt.delete("1.0", END)
    result.delete("1.0", END)

# 식 확인 버튼
btn_test = Button(frame_coefficient, text="식 확인", width=10, command=function_test)
btn_test.pack(side="right", padx=15, pady=5)
btn_test = Button(frame_integral, text="계산 결과", width=10, command=integral)
btn_test.pack(side="left", padx=15, pady=5)

menu = Menu(root)
menu_file = Menu(menu, tearoff=0)
menu_file.add_command(label="초기화", command=reset)
menu_file.add_separator()
menu_file.add_command(label="끝내기", command=root.quit)
menu.add_cascade(label="Menu", menu=menu_file)

root.config(menu=menu)
root.mainloop()