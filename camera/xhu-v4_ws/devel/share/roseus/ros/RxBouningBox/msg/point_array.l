;; Auto-generated. Do not edit!


(when (boundp 'RxBouningBox::point_array)
  (if (not (find-package "RXBOUNINGBOX"))
    (make-package "RXBOUNINGBOX"))
  (shadow 'point_array (find-package "RXBOUNINGBOX")))
(unless (find-package "RXBOUNINGBOX::POINT_ARRAY")
  (make-package "RXBOUNINGBOX::POINT_ARRAY"))

(in-package "ROS")
;;//! \htmlinclude point_array.msg.html


(defclass RxBouningBox::point_array
  :super ros::object
  :slots (_left _right _center ))

(defmethod RxBouningBox::point_array
  (:init
   (&key
    ((:left __left) (let (r) (dotimes (i 0) (push (instance RxBouningBox::point :init) r)) r))
    ((:right __right) (let (r) (dotimes (i 0) (push (instance RxBouningBox::point :init) r)) r))
    ((:center __center) (let (r) (dotimes (i 0) (push (instance RxBouningBox::point :init) r)) r))
    )
   (send-super :init)
   (setq _left __left)
   (setq _right __right)
   (setq _center __center)
   self)
  (:left
   (&rest __left)
   (if (keywordp (car __left))
       (send* _left __left)
     (progn
       (if __left (setq _left (car __left)))
       _left)))
  (:right
   (&rest __right)
   (if (keywordp (car __right))
       (send* _right __right)
     (progn
       (if __right (setq _right (car __right)))
       _right)))
  (:center
   (&rest __center)
   (if (keywordp (car __center))
       (send* _center __center)
     (progn
       (if __center (setq _center (car __center)))
       _center)))
  (:serialization-length
   ()
   (+
    ;; RxBouningBox/point[] _left
    (apply #'+ (send-all _left :serialization-length)) 4
    ;; RxBouningBox/point[] _right
    (apply #'+ (send-all _right :serialization-length)) 4
    ;; RxBouningBox/point[] _center
    (apply #'+ (send-all _center :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; RxBouningBox/point[] _left
     (write-long (length _left) s)
     (dolist (elem _left)
       (send elem :serialize s)
       )
     ;; RxBouningBox/point[] _right
     (write-long (length _right) s)
     (dolist (elem _right)
       (send elem :serialize s)
       )
     ;; RxBouningBox/point[] _center
     (write-long (length _center) s)
     (dolist (elem _center)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; RxBouningBox/point[] _left
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _left (let (r) (dotimes (i n) (push (instance RxBouningBox::point :init) r)) r))
     (dolist (elem- _left)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;; RxBouningBox/point[] _right
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _right (let (r) (dotimes (i n) (push (instance RxBouningBox::point :init) r)) r))
     (dolist (elem- _right)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;; RxBouningBox/point[] _center
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _center (let (r) (dotimes (i n) (push (instance RxBouningBox::point :init) r)) r))
     (dolist (elem- _center)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get RxBouningBox::point_array :md5sum-) "bfbc89fe3fdbe1c213bb38adf4a5ebe3")
(setf (get RxBouningBox::point_array :datatype-) "RxBouningBox/point_array")
(setf (get RxBouningBox::point_array :definition-)
      "point[] left
point[] right
point[] center

================================================================================
MSG: RxBouningBox/point
float64 x
float64 y 

")



(provide :RxBouningBox/point_array "bfbc89fe3fdbe1c213bb38adf4a5ebe3")


