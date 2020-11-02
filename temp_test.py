class AttrCls:
    def __init__(self, value, get_change="INIT"):
        self.value = value
        self.get_change = get_change

    def __getattr__(self, name):
        return getattr(self.value, name)

    def __repr__(self):
        return str(self.value)

    def __bool__(self):
        return bool(self.value)

    def __call__(self):
        return self.value()

    def __eq__(self, other):
        return self.value == other

    def __add__(self, other):
        return self.value + other

    def __sub__(self, other):
        return self.value - other

    def __mul__(self, other):
        return self.value * other

    def __truediv__(self, other):
        return self.value / other

    def __radd__(self, other):
        return other + self.value

    def __rsub__(self, other):
        return other - self.value

    def __rmul__(self, other):
        return other * self.value

    def __rtruediv__(self, other):
        return other / self.value


def change_detection(cls):
    def __getattribute__(self, name):
        pass

    def __setattr__(self, name, value):
        pass

    def __delattr__(self, name):
        pass

    setattr(cls, '__getattribute__', __getattribute__)
    setattr(cls, '__setattr__', __setattr__)
    setattr(cls, '__delattr__', __delattr__)

    return cls


y = AttrCls(11)
x = AttrCls(12)

print(y+x, y.get_change)
print(y-x, y.get_change)
print(y*x, y.get_change)
print(y/x, y.get_change)
