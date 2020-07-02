# #!/bin/python3

# import math
# import os
# import random
# import re
# import sys


# #
# # Complete the 'calculate_total_owed' function below.
# #
# # The function is expected to return an INTEGER.
# # The function accepts STRING_ARRAY actions as parameter.
# #

# id_pattern = ".*id=(\d+)"
# currency_pattern = ".*amount=(\d+)"


# def processString(s):
#     first_split = s.split(" ")
#     state = first_split[0]
#     id_match = re.search(id_pattern, first_split[1].lower())
#     ID = "empty"
#     if(id_match):
#         ID = id_match.group(1)

#     if(state == "PAY:"):
#         return state, ID, None

#     if(s[-3:].lower() != "usd"):
#         return "INVALID", 0, 0

#     amount_match = re.search(currency_pattern, first_split[1])
#     amount = "empty"
#     if(amount_match):
#         amount = amount_match.group(1)

#     return state, ID, amount


# class Invoice():
#     def __init__(self, state, ID, amount):
#         self.state = state
#         self.ID = ID
#         self.amount = amount

#     def finalize(self, state, ID, amount):
#         self.state = state
#         self.amount = amount

#     def pay(self, state):
#         self.state = state
#         self.amount = 0


# def calculate_total_owed(actions):
#     # Write your code here
#     owed_amount = 0
#     invoices = {}
#     for action in actions:
#         state, ID, amount = processString(action)
#         if(ID == "empty"):
#             continue
#         if(state == "CREATE:" and ID not in invoices):
#             obj = Invoice(state, ID, amount)
#             invoices[ID] = obj
#         elif(state == "FINALIZE:"):
#             if(ID in invoices and invoices[ID].state == "CREATE:"):
#                 invoices[ID].finalize(state, ID, amount)
#         elif(state == "PAY:"):
#             if(ID in invoices and invoices[ID].state == "FINALIZE:"):
#                 invoices[ID].pay(state)
#         else:   # invalid
#             pass

#     for key, value in invoices.items():
#         owed_amount += int(value.amount)
#         # print(value.state, value.ID, value.amount)

#     return owed_amount


# if __name__ == '__main__':

#     actions = ["CREATE: id=13&amount=800&currency=USD",
#                "FINALIZE: id=13&amount=900&currency=USD",
#                "FINALIZE: id=10&amount=900&currency=USD",
#                "CREATE: id=10&amount=800&currency=USD",
#                "FINALIZE: id=10&amount=1300&currency=USD",
#                "PAY: id=13"
#                ]

#     result = calculate_total_owed(actions)

#     print(result)
