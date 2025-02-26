words = {"python", "hi", "hello"}
word = words.pop().lower()

name = input("Enter your name: ")
print(f"Hello {name}, let's play !")

guessed_word =['_'] * len(word)

New_word =""
count=7
i = 0
while i <  7:
    letter = input("Enter a letter: ").lower()
    print(f"You have {count-i} Guesses left")
    if letter in word:
        if letter in guessed_word:
            i_guessed_word = guessed_word.index(letter)
            i_word = word.index(letter, i_guessed_word+1)
        else:
            i_word = word.index(letter)
        guessed_word[i_word] = letter
        New_word = "".join(guessed_word)
        print(New_word)
    else:
        print("Guess another letter!")

    if New_word == word:
        print(f"Congratulations {name}! You guessed the word")
        break
    i +=1