import uuid
import datetime

BOOKING_STATUS = ['Booked', 'Reserved']
ALTER_BOOKING_STATUS = ['Closed', 'Canceled']
DATE_FORMAT = "%d%m%Y"


class Booking:
    id_counter = 1

    def __init__(self, bookingId: int, tableNo: int, bookingDate: str, guests: int, status: str):
        self.bookingId = bookingId
        self.tableNo = tableNo
        self.bookingDate = bookingDate
        self.guests = guests
        self.status = status
        self._date = datetime.datetime.strptime(
            bookingDate, DATE_FORMAT).date()
        Booking.id_counter += 1


class Restaurant:
    def __init__(self, tableList: dict, bookingList: list):
        self.tableList = tableList
        self.bookingList = bookingList

    def isAvailable(self, tableNo, bookingDate):
        for booking in self.bookingList:
            if booking.tableNo == tableNo and booking.bookingDate == bookingDate and booking.status in BOOKING_STATUS:
                return False
        return True

    def bookTable(self, guests: int, date: str, status: str):
        for k, v in self.tableList.items():
            if v == guests:
                if self.isAvailable(k, date):
                    self.bookingList.append(
                        Booking(Booking.id_counter, k, date, guests, status))
                else:
                    pass

    def updateBookingStatus(self, date: str)
    given_date = datetime.datetime.strptime(date, DATE_FORMAT).date()
    one_past = given_date - datetime.timedelta(days=1)
     two_past = given_date - datetime.timedelta(days=2)
      for booking in self.bookingList:
           if booking._date <= two_past and booking.status == BOOKING_STATUS[1]:
                booking.status = ALTER_BOOKING_STATUS[1]
            if booking._date <= one_past and booking.status == BOOKING_STATUS[0]:
                booking.status = ALTER_BOOKING_STATUS[0]
