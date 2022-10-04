import cv2
import matplotlib.pyplot as plt
import numpy as np


def canny_edge_detector(frame):
    
    
    gray = cv2.cvtColor(frame, cv2.COLOR_RGB2GRAY)
    
    
    blur = cv2.GaussianBlur(gray, (5, 5), 0)
    
    
    canny = cv2.Canny(blur, 50, 150)
    
    return canny  


def ROI_mask(image):
    
    height = image.shape[0]
    width = image.shape[1]

    
        
    polygons = np.array([ 
        [(0, height), (round(width/2), round(height/2)), (1000, height)] 
        ]) 
    
    mask = np.zeros_like(image) 
    cv2.fillPoly(mask, polygons, 255)  
    
    
    masked_image = cv2.bitwise_and(image, mask)
    
    return masked_image

def get_coordinates (image, params):
     
    slope, intercept = params 
    y1 = image.shape[0]     
    y2 = int(y1 * (3/5))
    x1 = int((y1 - intercept) / slope) 
    x2 = int((y2 - intercept) / slope)
    return np.array([x1, y1, x2, y2])

def avg_lines(image, lines): 
    
    left = [] 
    right = [] 
    
    for line in lines: 
        x1, y1, x2, y2 = line.reshape(4)
          
        
        params = np.polyfit((x1, x2), (y1, y2), 1)  
        slope = params[0] 
        y_intercept = params[1] 
        
        if slope < 0: 
            left.append((slope, y_intercept)) 
        else: 
            right.append((slope, y_intercept)) 
    
    
    left_avg = np.average(left, axis = 0) 
    right_avg = np.average(right, axis = 0) 
    
    
    left_line = get_coordinates(image, left_avg) 
    right_line = get_coordinates(image, right_avg)
    
    return np.array([left_line, right_line])

def draw_lines(image, lines, thickness): 
   
    print(lines)
    line_image = np.zeros_like(image)
    color=[0, 0, 255]
    
    if lines is not None: 
        for x1, y1, x2, y2 in lines:
                    cv2.line(line_image, (x1, y1), (x2, y2), color, thickness)

            
    
    combined_image = cv2.addWeighted(image, 0.8, line_image, 1.0, 0.0)
    
    return combined_image

inputimage = cv2.imread("solidWhiteCurve.jpg")

plt.figure()
plt.imshow(cv2.cvtColor(inputimage, cv2.COLOR_BGR2RGB))
canny_edges = canny_edge_detector(inputimage)
plt.figure()
plt.imshow(cv2.cvtColor(canny_edges, cv2.COLOR_BGR2RGB))
plt.show()
cropped_image = ROI_mask(canny_edges)
plt.figure()
plt.imshow(cv2.cvtColor(cropped_image, cv2.COLOR_BGR2RGB))
plt.show()

lines = cv2.HoughLinesP(cropped_image,rho=2,theta=np.pi / 180,threshold=100,lines=np.array([]),minLineLength=40,maxLineGap=25)

# Visualisations
averaged_lines = avg_lines (inputimage, lines)              
combined_image = draw_lines(inputimage, averaged_lines, 5)  
plt.figure()
plt.imshow(cv2.cvtColor(combined_image, cv2.COLOR_BGR2RGB))
plt.show()
