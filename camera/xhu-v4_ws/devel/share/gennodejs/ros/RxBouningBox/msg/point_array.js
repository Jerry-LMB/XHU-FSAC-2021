// Auto-generated. Do not edit!

// (in-package RxBouningBox.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let point = require('./point.js');

//-----------------------------------------------------------

class point_array {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.left = null;
      this.right = null;
      this.center = null;
    }
    else {
      if (initObj.hasOwnProperty('left')) {
        this.left = initObj.left
      }
      else {
        this.left = [];
      }
      if (initObj.hasOwnProperty('right')) {
        this.right = initObj.right
      }
      else {
        this.right = [];
      }
      if (initObj.hasOwnProperty('center')) {
        this.center = initObj.center
      }
      else {
        this.center = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type point_array
    // Serialize message field [left]
    // Serialize the length for message field [left]
    bufferOffset = _serializer.uint32(obj.left.length, buffer, bufferOffset);
    obj.left.forEach((val) => {
      bufferOffset = point.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [right]
    // Serialize the length for message field [right]
    bufferOffset = _serializer.uint32(obj.right.length, buffer, bufferOffset);
    obj.right.forEach((val) => {
      bufferOffset = point.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [center]
    // Serialize the length for message field [center]
    bufferOffset = _serializer.uint32(obj.center.length, buffer, bufferOffset);
    obj.center.forEach((val) => {
      bufferOffset = point.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type point_array
    let len;
    let data = new point_array(null);
    // Deserialize message field [left]
    // Deserialize array length for message field [left]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.left = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.left[i] = point.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [right]
    // Deserialize array length for message field [right]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.right = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.right[i] = point.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [center]
    // Deserialize array length for message field [center]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.center = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.center[i] = point.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 16 * object.left.length;
    length += 16 * object.right.length;
    length += 16 * object.center.length;
    return length + 12;
  }

  static datatype() {
    // Returns string type for a message object
    return 'RxBouningBox/point_array';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'bfbc89fe3fdbe1c213bb38adf4a5ebe3';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    point[] left
    point[] right
    point[] center
    
    ================================================================================
    MSG: RxBouningBox/point
    float64 x
    float64 y 
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new point_array(null);
    if (msg.left !== undefined) {
      resolved.left = new Array(msg.left.length);
      for (let i = 0; i < resolved.left.length; ++i) {
        resolved.left[i] = point.Resolve(msg.left[i]);
      }
    }
    else {
      resolved.left = []
    }

    if (msg.right !== undefined) {
      resolved.right = new Array(msg.right.length);
      for (let i = 0; i < resolved.right.length; ++i) {
        resolved.right[i] = point.Resolve(msg.right[i]);
      }
    }
    else {
      resolved.right = []
    }

    if (msg.center !== undefined) {
      resolved.center = new Array(msg.center.length);
      for (let i = 0; i < resolved.center.length; ++i) {
        resolved.center[i] = point.Resolve(msg.center[i]);
      }
    }
    else {
      resolved.center = []
    }

    return resolved;
    }
};

module.exports = point_array;
