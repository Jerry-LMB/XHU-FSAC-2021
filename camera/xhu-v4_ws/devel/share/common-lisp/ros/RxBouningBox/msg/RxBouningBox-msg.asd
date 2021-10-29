
(cl:in-package :asdf)

(defsystem "RxBouningBox-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "point" :depends-on ("_package_point"))
    (:file "_package_point" :depends-on ("_package"))
    (:file "point_array" :depends-on ("_package_point_array"))
    (:file "_package_point_array" :depends-on ("_package"))
  ))