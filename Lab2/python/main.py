import func

print('Work shift starts at 8:00 and end at 18:00')
text_to_write = func.capture_text()

func.write_empty_file("input.txt", text_to_write)
text = func.read_file("input.txt")
print(f"Text on input:\n{text}\n")

number = int(input("Enter number of customers:"))
isEnough = func.count_time(text, number)
if(isEnough):
    print("There is enough time for", number, "customer")
else:
    print("There is not enough time for", number, "customer")