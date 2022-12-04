from cs50 import get_string
import string

text = input("Enter Text: ")

#count letters
l = 0.0;
for i in range(len(text)):
    if(text[i].isalpha()):
        l = l + 1

#count words
w = 1.0
for i in range(len(text)):
    if(text[i] == ' '):
        w = w + 1

    #count sentences
s = 0.0
for i in range(len(text)):
    if((text[i] == '.') or (text[i] == '!') or (text[i] == '?')):
        s = s + 1

L = ( l / w ) * 100
S = ( s /  w ) * 100
index = round(0.0588 * L - 0.296 * S - 15.8)

if(index < 1):
    print("Before Grade 1\n")

elif(index >= 16):
    print("Grade 16+\n")

else:
    print("Grade ", index)




#int count_letters(string text){
 #   int count = 0;
  #  for(int i = 0; i < strlen(text); i++){
   #     if(isalpha(text[i]) != 0){
    #        count++;

   # return count;


#int count_words(string text){
 #   int count = 1;
  #  for(int i = 0; i < strlen(text); i++){
   #     if(text[i] == ' '){
    #        count++;

   # return count;


#int count_sentences(string text){
 #   int count = 0;
  #  for(int i = 0; i < strlen(text); i++){
   #     if((text[i] == '.') || (text[i] == '!') || (text[i] == '?')){
    #        count++;

    #return count;
