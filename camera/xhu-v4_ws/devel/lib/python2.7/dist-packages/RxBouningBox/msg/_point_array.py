# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from RxBouningBox/point_array.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import RxBouningBox.msg

class point_array(genpy.Message):
  _md5sum = "bfbc89fe3fdbe1c213bb38adf4a5ebe3"
  _type = "RxBouningBox/point_array"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """point[] left
point[] right
point[] center

================================================================================
MSG: RxBouningBox/point
float64 x
float64 y 
"""
  __slots__ = ['left','right','center']
  _slot_types = ['RxBouningBox/point[]','RxBouningBox/point[]','RxBouningBox/point[]']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       left,right,center

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(point_array, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.left is None:
        self.left = []
      if self.right is None:
        self.right = []
      if self.center is None:
        self.center = []
    else:
      self.left = []
      self.right = []
      self.center = []

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      length = len(self.left)
      buff.write(_struct_I.pack(length))
      for val1 in self.left:
        _x = val1
        buff.write(_get_struct_2d().pack(_x.x, _x.y))
      length = len(self.right)
      buff.write(_struct_I.pack(length))
      for val1 in self.right:
        _x = val1
        buff.write(_get_struct_2d().pack(_x.x, _x.y))
      length = len(self.center)
      buff.write(_struct_I.pack(length))
      for val1 in self.center:
        _x = val1
        buff.write(_get_struct_2d().pack(_x.x, _x.y))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      if self.left is None:
        self.left = None
      if self.right is None:
        self.right = None
      if self.center is None:
        self.center = None
      end = 0
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.left = []
      for i in range(0, length):
        val1 = RxBouningBox.msg.point()
        _x = val1
        start = end
        end += 16
        (_x.x, _x.y,) = _get_struct_2d().unpack(str[start:end])
        self.left.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.right = []
      for i in range(0, length):
        val1 = RxBouningBox.msg.point()
        _x = val1
        start = end
        end += 16
        (_x.x, _x.y,) = _get_struct_2d().unpack(str[start:end])
        self.right.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.center = []
      for i in range(0, length):
        val1 = RxBouningBox.msg.point()
        _x = val1
        start = end
        end += 16
        (_x.x, _x.y,) = _get_struct_2d().unpack(str[start:end])
        self.center.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      length = len(self.left)
      buff.write(_struct_I.pack(length))
      for val1 in self.left:
        _x = val1
        buff.write(_get_struct_2d().pack(_x.x, _x.y))
      length = len(self.right)
      buff.write(_struct_I.pack(length))
      for val1 in self.right:
        _x = val1
        buff.write(_get_struct_2d().pack(_x.x, _x.y))
      length = len(self.center)
      buff.write(_struct_I.pack(length))
      for val1 in self.center:
        _x = val1
        buff.write(_get_struct_2d().pack(_x.x, _x.y))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      if self.left is None:
        self.left = None
      if self.right is None:
        self.right = None
      if self.center is None:
        self.center = None
      end = 0
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.left = []
      for i in range(0, length):
        val1 = RxBouningBox.msg.point()
        _x = val1
        start = end
        end += 16
        (_x.x, _x.y,) = _get_struct_2d().unpack(str[start:end])
        self.left.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.right = []
      for i in range(0, length):
        val1 = RxBouningBox.msg.point()
        _x = val1
        start = end
        end += 16
        (_x.x, _x.y,) = _get_struct_2d().unpack(str[start:end])
        self.right.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.center = []
      for i in range(0, length):
        val1 = RxBouningBox.msg.point()
        _x = val1
        start = end
        end += 16
        (_x.x, _x.y,) = _get_struct_2d().unpack(str[start:end])
        self.center.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_2d = None
def _get_struct_2d():
    global _struct_2d
    if _struct_2d is None:
        _struct_2d = struct.Struct("<2d")
    return _struct_2d
