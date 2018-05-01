 
import smtplib
server = smtplib.SMTP('smtp.gmail.com', 587)

server.starttls()

#Next, log in to the server
server.login("ayanosmanphotog@gmail.com", "Jamilo64.")

#Send the mail
msg = "Hello!" # The /n separates the message from the headers
server.sendmail("ayanosmanphotog@gmail.com", "osmana13@coventry.ac.uk", msg)