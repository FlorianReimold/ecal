# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: house.proto

from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='house.proto',
  package='Environment',
  syntax='proto3',
  serialized_options=None,
  serialized_pb=b'\n\x0bhouse.proto\x12\x0b\x45nvironment\"\x16\n\x05House\x12\r\n\x05rooms\x18\x01 \x01(\x05\x62\x06proto3'
)




_HOUSE = _descriptor.Descriptor(
  name='House',
  full_name='Environment.House',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='rooms', full_name='Environment.House.rooms', index=0,
      number=1, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=28,
  serialized_end=50,
)

DESCRIPTOR.message_types_by_name['House'] = _HOUSE
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

House = _reflection.GeneratedProtocolMessageType('House', (_message.Message,), {
  'DESCRIPTOR' : _HOUSE,
  '__module__' : 'house_pb2'
  # @@protoc_insertion_point(class_scope:Environment.House)
  })
_sym_db.RegisterMessage(House)


# @@protoc_insertion_point(module_scope)
