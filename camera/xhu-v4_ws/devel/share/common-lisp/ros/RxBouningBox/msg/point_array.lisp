; Auto-generated. Do not edit!


(cl:in-package RxBouningBox-msg)


;//! \htmlinclude point_array.msg.html

(cl:defclass <point_array> (roslisp-msg-protocol:ros-message)
  ((left
    :reader left
    :initarg :left
    :type (cl:vector RxBouningBox-msg:point)
   :initform (cl:make-array 0 :element-type 'RxBouningBox-msg:point :initial-element (cl:make-instance 'RxBouningBox-msg:point)))
   (right
    :reader right
    :initarg :right
    :type (cl:vector RxBouningBox-msg:point)
   :initform (cl:make-array 0 :element-type 'RxBouningBox-msg:point :initial-element (cl:make-instance 'RxBouningBox-msg:point)))
   (center
    :reader center
    :initarg :center
    :type (cl:vector RxBouningBox-msg:point)
   :initform (cl:make-array 0 :element-type 'RxBouningBox-msg:point :initial-element (cl:make-instance 'RxBouningBox-msg:point))))
)

(cl:defclass point_array (<point_array>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <point_array>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'point_array)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name RxBouningBox-msg:<point_array> is deprecated: use RxBouningBox-msg:point_array instead.")))

(cl:ensure-generic-function 'left-val :lambda-list '(m))
(cl:defmethod left-val ((m <point_array>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader RxBouningBox-msg:left-val is deprecated.  Use RxBouningBox-msg:left instead.")
  (left m))

(cl:ensure-generic-function 'right-val :lambda-list '(m))
(cl:defmethod right-val ((m <point_array>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader RxBouningBox-msg:right-val is deprecated.  Use RxBouningBox-msg:right instead.")
  (right m))

(cl:ensure-generic-function 'center-val :lambda-list '(m))
(cl:defmethod center-val ((m <point_array>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader RxBouningBox-msg:center-val is deprecated.  Use RxBouningBox-msg:center instead.")
  (center m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <point_array>) ostream)
  "Serializes a message object of type '<point_array>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'left))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'left))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'right))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'right))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'center))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'center))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <point_array>) istream)
  "Deserializes a message object of type '<point_array>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'left) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'left)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'RxBouningBox-msg:point))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'right) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'right)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'RxBouningBox-msg:point))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'center) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'center)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'RxBouningBox-msg:point))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<point_array>)))
  "Returns string type for a message object of type '<point_array>"
  "RxBouningBox/point_array")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'point_array)))
  "Returns string type for a message object of type 'point_array"
  "RxBouningBox/point_array")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<point_array>)))
  "Returns md5sum for a message object of type '<point_array>"
  "bfbc89fe3fdbe1c213bb38adf4a5ebe3")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'point_array)))
  "Returns md5sum for a message object of type 'point_array"
  "bfbc89fe3fdbe1c213bb38adf4a5ebe3")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<point_array>)))
  "Returns full string definition for message of type '<point_array>"
  (cl:format cl:nil "point[] left~%point[] right~%point[] center~%~%================================================================================~%MSG: RxBouningBox/point~%float64 x~%float64 y ~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'point_array)))
  "Returns full string definition for message of type 'point_array"
  (cl:format cl:nil "point[] left~%point[] right~%point[] center~%~%================================================================================~%MSG: RxBouningBox/point~%float64 x~%float64 y ~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <point_array>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'left) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'right) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'center) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <point_array>))
  "Converts a ROS message object to a list"
  (cl:list 'point_array
    (cl:cons ':left (left msg))
    (cl:cons ':right (right msg))
    (cl:cons ':center (center msg))
))
