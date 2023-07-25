import cv2
import imutils
from arduino import heart_rate_sensor



def printer():
        cap = cv2.VideoCapture('pexels-aleksandr-neplokhov-4168522-1440x1080-25fps.mp4')
        while cap.isOpened():
            ret, frame = cap.read()
            frame = imutils.resize(frame,height=1080,width=1080)
            if ret:
                bpm = heart_rate_sensor()
                cv2.putText(frame, bpm, (10, 200), cv2.FONT_HERSHEY_SIMPLEX, 5, (0, 0, 255), 6)
                cv2.imshow('Frame', frame)
                if cv2.waitKey(25) & 0xFF == ord('q' or 'Q'):
                    break
            else:
                break
        cap.release()
        cv2.destroyAllWindows()



printer()