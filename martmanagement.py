class shop:
  def SHOPE(self):
    file3 =open('FILE3.txt','r')
    user = input('SHOPKEEPER ENTER YOUR USERNAME: ')
    pascode = input('SHOPKEEPER ENTER YOUR PASSCODE: ')
    ALL_PROD = {'250 ML':500,'500 ML':450,'1L':150,'1.5L':350,'2.25':300,'WALLS FEAST':350,'WALLS DONUT':550,'WALLS CLASSIC KULFA':250,'WALLS CORNETTO BROWNIE':150,'WALLS CHOCOLATE BAR':200,'MILK PACK 180 ML':450,'MILK PACK 225 ML':400,'MILK PACK 500 ML':250,'MILK PACK 1L':350,'CHEETOS FLAMIN JUMBO':450,'WAVY BBQ':400,'LAYS PAPRIKA':250,'TWICH MASALA POTATO':350,'SALANTY JALAPENO JUMBO':350,'SNACKERS PIZZA':350,'KURKURE MASALA':350}
    print(ALL_PROD)
    try:
      user == 'SAAD' or user == 'ZAEEM' or user == 'QIRAT' or user == 'HANIA' and pascode == '1234'
    except(ValueError):
      print("YOU ENTERED WRONG USERNAME OR SECRET CODE, TRY AGAIN") 
    finally:
      prod_cat = input('ENTER PRODUCT NAME: ')
      prod_quat = eval(input('ENTER PRODUCT QUANTITY YOU WANT TO: '))
      for i,j in ALL_PROD.items():
        if prod_cat == i:
          j1 = j + prod_quat
          ALL_PROD.update({i : j1})
          print(ALL_PROD)
    file3_0 = str(ALL_PROD)
    file3 =open('FILE3.txt','w')
    file3.write(file3_0)
    file3.close()
      

class inventory:
  def __init__(self,cust_name,cust_phno):
    self.cust_name = cust_name
    self.cust_phno = cust_phno

  def customer_details(self):
    pass

  def Car(self):
    file1 = open('FILE1.txt','r')
    file1 = open('FILE1.txt','w')
    file2 = open('FILE2.txt','r')
    file2 = open('FILE2.txt','w')
    ALL_PROD = {'250 ML':[500,50],'500 ML':[450,60],'1L':[150,80],'1.5L':[350,90],'2.25':[300,110],'WALLS FEAST':[350,70],'WALLS DONUT':[550,60],'WALLS CLASSIC KULFA':[250,80],'WALLS CORNETTO BROWNIE':[150,110],'WALLS CHOCOLATE BAR':[200,120],'MILK PACK 180 ML':[450,20],'MILK PACK 225 ML':[400,30],'MILK PACK 500 ML':[250,70],'MILK PACK 1L':[350,130],'CHEETOS FLAMIN JUMBO':[450,50],'WAVY BBQ':[400,30],'LAYS PAPRIKA':[250,50],'TWICH MASALA POTATO':[350,10],'SALANTY JALAPENO JUMBO':[350,50],'SNACKERS PIZZA':[350,20],'KURKURE MASALA':[350,50]}
    TOTAL_PROD = []
    TOTAL_QUAN = []
    TOTAL_PRICE = []
    debit_cash = input('DO YOU WANT BILL BY CASH OR DEBIT(IN UPPER CASE LETTERS): ')
    things_order = eval(input('ENTER HOW MANY PRODUCTS YOU WANT FROM DIFFERENT CATEGORIES(ENETR IN NUMBERS): '))
    for i in range(0,things_order):
      print('-------------- WE OFFER THESE PRODUCTS --------------')
      print('-------------- DRINKS, ICE CREAM, DAIRY, SNACKS & CHIPS--------------')
      cust_prod_catg = input('ENTER PRODUCT CATEGORY(IN UPPER CASE LETTERS): ')

#____________________________________________________________________________DRINKS_______________________________________________________________________________________________________________________________________
      if cust_prod_catg == 'DRINKS' or cust_prod_catg == 'Drinks' or cust_prod_catg == 'drinks':
        print('-------------- DRINKS --------------')
        print('--------- PEPSI, 7UP, DEW(250 ML) = 50/- RS ----------')
        print('--------- PEPSI, 7UP, DEW(500 ML) = 60/- RS ----------')
        print('--------- PEPSI, 7UP, DEW(1L) = 80/- RS --------------')
        print('--------- PEPSI, 7UP, DEW(1.5L) = 90/- RS ------------')
        print('--------- PEPSI, 7UP, DEW(2.25L)= 120/- RS -----------')
        cust_prod = input('ENTER PRODUCT NAME(IN UPPER CASE LETTERS): ')
        print('---------------- WHICH ONE YOU WANT ------------------')
        print('--------- (250 ML, 500 ML, 1L, 1.5L, 2.25L) ----------')
        prod_spect = input('ENTER WHICH ONE YOU WANT')
        cust_quant = eval(input('ENTER QUANTITY YOU WANT(IN NUMBERS): '))
        cold_drinks = {'250 ML':[500,50],'500 ML':[450,60],'1L':[150,80],'1.5L':[350,90],'2.25':[300,110]}
        for a,b in cold_drinks.items():
          prod_quantity = 0
          prod_price = 0
          if prod_spect == a:      
            for i in b:
              if i > 100:
                prod_quantity = i
              elif i > 40:
                prod_price = i
            if cust_prod == 'PEPSI' or cust_prod == '7UP' or cust_prod == 'DEW' or cust_prod == 'Pepsi' or cust_prod == '7up' or cust_prod == 'Dew' or cust_prod == 'pepsi' or cust_prod == 'dew':
              if debit_cash == 'DEBIT' or debit_cash == 'Debit' or debit_cash == 'debit':
                prod_quantity = prod_quantity - cust_quant
                price = prod_price * cust_quant
                GST = (price*0.17)/100 
                total_GST = price + GST
                TOTAL_PROD.append(cust_prod)
                TOTAL_QUAN.append(cust_quant)
                TOTAL_PRICE.append(total_GST)
                ALL_PROD.update({a : prod_quantity})  
              elif debit_cash == 'CASH' or debit_cash == 'Cash' or debit_cash == 'cash':
                prod_quantity = prod_quantity - cust_quant
                price = prod_price * cust_quant
                GST = (price*0.17)/100 
                total_GST = price + GST
                TOTAL_PROD.append(cust_prod)
                TOTAL_QUAN.append(cust_quant)
                TOTAL_PRICE.append(total_GST)
                ALL_PROD.update({a : prod_quantity})  
  #____________________________________________________________________________ICE CREAM_______________________________________________________________________________________________________________________________________
                
      elif cust_prod_catg == 'ICE CREAM' or cust_prod_catg == 'Ice cream' or cust_prod_catg == 'ice cream':
        print('-------------- ICE CREAM --------------')
        print('--------- WALLS FEAST = 70/- RS ----------')
        print('--------- WALLS DONUT = 60/- RS ----------')
        print('--------- WALLS CLASSIC KULFA = 80/- RS --------------')
        print('--------- WALLS CORNETTO BROWNIE = 110/- RS ------------')
        print('--------- WALLS CHOCOLATE BAR = 120/- RS -----------')
        cust_prod = input('ENTER PRODUCT NAME(IN UPPER CASE LETTERS): ')
        cust_quant = eval(input('ENTER QUANTITY YOU WANT(IN NUMBERS): ')) 
        ice_creams = {'WALLS FEAST':[350,70],'WALLS DONUT':[550,60],'WALLS CLASSIC KULFA':[250,80],'WALLS CORNETTO BROWNIE':[150,110],'WALLS CHOCOLATE BAR':[200,120]}
        for a,b in ice_creams.items():
          prod_quantity = 0
          prod_price = 0
          if cust_prod == a:      
            for i in b:
              if i > 100:
                prod_quantity = i
              elif i > 40:
                prod_price = i
            if cust_prod == 'WALLS FEAST' or cust_prod == 'WALLS DONUT' or cust_prod == 'WALLS CLASSIC KULFA' or cust_prod == 'WALLS CORNETTO BROWNIE' or cust_prod == 'WALLS CHOCOLATE BAR':
              if debit_cash == 'DEBIT' or debit_cash == 'Debit' or debit_cash == 'debit':
                prod_quantity = prod_quantity - cust_quant
                price = prod_price * cust_quant
                GST = (price*0.17)/100 
                total_GST = price + GST
                TOTAL_PROD.append(cust_prod)
                TOTAL_QUAN.append(cust_quant)
                TOTAL_PRICE.append(total_GST)
                ALL_PROD.update({a : prod_quantity}) 
              elif debit_cash == 'CASH' or debit_cash == 'Cash' or debit_cash == 'cash':
                prod_quantity = prod_quantity - cust_quant
                price = prod_price * cust_quant
                GST = (price*0.17)/100 
                total_GST = price + GST
                TOTAL_PROD.append(cust_prod)
                TOTAL_QUAN.append(cust_quant)
                TOTAL_PRICE.append(total_GST)
                ALL_PROD.update({a : prod_quantity}) 
  #____________________________________________________________________________DAIRY_______________________________________________________________________________________________________________________________________
      
      elif cust_prod_catg == 'DAIRY' or cust_prod_catg == 'Dairy' or cust_prod_catg == 'dairy':
        print('-------------- DAIRY --------------')
        print('--------- MILK PACK (180 ML) = 20/- RS ----------')
        print('--------- MILK PACK (225 ML) = 30/- RS --------------')
        print('--------- MILK PACK (500 ML) = 70/- RS ------------')
        print('--------- MILK PACK (1L) = 130/- RS -----------')
        cust_prod = input('ENTER PRODUCT NAME(IN UPPER CASE LETTERS): ')
        print('--------- (180 ML, 225 ML, 500, 1L) ----------')
        prod_spect = input('ENTER WHICH ONE YOU WANT')
        cust_quant = eval(input('ENTER QUANTITY YOU WANT(IN NUMBERS): '))
        dairy = {'MILK PACK 180 ML':[450,20],'MILK PACK 225 ML':[400,30],'MILK PACK 500 ML':[250,70],'MILK PACK 1L':[350,130]}
        for a,b in dairy.items():
          prod_quantity = 0
          prod_price = 0
          if prod_spect == a or cust_prod == a:      
            for i in b:
              if i > 100:
                prod_quantity = i
              elif i > 10:
                prod_price = i
            if cust_prod == 'MILK PACK (180 ML)' or cust_prod == 'MILK PACK (225 ML)' or cust_prod == 'MILK PACK (500 ML)' or cust_prod == 'MILK PACK (1L)' or  cust_prod == 'MILK PACK' or cust_prod == 'Milk pack' or cust_prod == 'milk pack'   :
              if debit_cash == 'DEBIT' or debit_cash == 'Debit' or debit_cash == 'debit':
                prod_quantity = prod_quantity - cust_quant
                price = prod_price * cust_quant
                GST = (price*0.17)/100 
                total_GST = price + GST
                TOTAL_PROD.append(cust_prod)
                TOTAL_QUAN.append(cust_quant)
                TOTAL_PRICE.append(total_GST)
                ALL_PROD.update({a : prod_quantity}) 
              elif debit_cash == 'CASH' or debit_cash == 'Cash' or debit_cash == 'cash':
                prod_quantity = prod_quantity - cust_quant
                price = prod_price * cust_quant
                GST = (price*0.17)/100 
                total_GST = price + GST
                TOTAL_PROD.append(cust_prod)
                TOTAL_QUAN.append(cust_quant)
                TOTAL_PRICE.append(total_GST)
                ALL_PROD.update({a : prod_quantity}) 
  #____________________________________________________________________________SNACKS & CHIPS_______________________________________________________________________________________________________________________________________
      elif cust_prod_catg == 'SNACKS & CHIPS' or cust_prod_catg == 'Snacks & chips' or cust_prod_catg == 'snacks & chips': 
        print('-------------- SNACKS & CHIPS --------------')
        print('--------- CHEETOS FLAMIN JUMBO = 50/- RS ----------')
        print('--------- WAVY BBQ = 30/- RS --------------')
        print('--------- LAYS PAPRIKA = 50/- RS ------------')
        print('--------- TWICH MASALA POTATO = 10/- RS -----------')
        print('--------- SALANTY JALAPENO JUMBO = 50/- RS ----------')
        print('--------- SNACKERS PIZZA = 20/- RS --------------')
        print('--------- KURKURE MASALA = 50/- RS ------------')
        cust_prod = input('ENTER PRODUCT NAME(IN UPPER CASE LETTERS): ')
        cust_quant = eval(input('ENTER QUANTITY YOU WANT(IN NUMBERS): '))
        snacks = {'CHEETOS FLAMIN JUMBO':[450,50],'WAVY BBQ':[400,30],'LAYS PAPRIKA':[250,50],'TWICH MASALA POTATO':[350,10],'SALANTY JALAPENO JUMBO':[350,50],'SNACKERS PIZZA':[350,20],'KURKURE MASALA':[350,50]}
        for a,b in snacks.items():
          prod_quantity = 0
          prod_price = 0
          if cust_prod == a:      
            for i in b:
              if i > 100:
                prod_quantity = i
              elif i > 10:
                prod_price = i
            if cust_prod == 'CHEETOS FLAMIN JUMBO' or cust_prod == 'WAVY BBQ' or cust_prod == 'LAYS PAPRIKA' or cust_prod == 'TWICH MASALA POTATO' or cust_prod == 'SALANTY JALAPENO JUMBO' or cust_prod == 'SNACKERS PIZZA' or cust_prod == 'KURKURE MASALA' :
              if debit_cash == 'DEBIT' or debit_cash == 'Debit' or debit_cash == 'debit':
                prod_quantity = prod_quantity - cust_quant
                price = prod_price * cust_quant
                GST = (price*0.17)/100 
                total_GST = price + GST
                TOTAL_PROD.append(cust_prod)
                TOTAL_QUAN.append(cust_quant)
                TOTAL_PRICE.append(total_GST)
                ALL_PROD.update({a : prod_quantity})  
              elif debit_cash == 'CASH' or debit_cash == 'Cash' or debit_cash == 'cash':
                prod_quantity = prod_quantity - cust_quant
                price = prod_price * cust_quant
                GST = (price*0.17)/100 
                total_GST = price + GST               
                TOTAL_PROD.append(cust_prod)
                TOTAL_QUAN.append(cust_quant)
                TOTAL_PRICE.append(total_GST)
                ALL_PROD.update({a : prod_quantity})  
    file1 = open('FILE1.txt','w')
    file1.write(self.cust_name)
    modi0 = str(self.cust_phno)
    file1.write(modi0)
    modi1 = str(TOTAL_PROD)
    modi2 = str(TOTAL_PRICE)
    file1.write(modi1)
    file1.write(modi2)
    file1.close()
    print('')
    print('') 
    print('')
    print('------------------ HELLO WORLD MART ------------------')
    print(time.strftime('%A %b/%d/%y %I:%M %p'))
    print('-------------- CUSTOMER DETAILS --------------')
    print('CUSTOMER NAME: ',self.cust_name)
    print('CUSTOMER PHONE NUMBER: ',self.cust_phno)
    print('-------------- CUSTOMER PAYMENT METHOD --------------')
    print('YOU SELECTED: ',debit_cash,'METHOD.')
    print('-------------- PURCHASE DETAILS --------------')
    print('NAME OF ITEMS BOUGHT ARE: ',TOTAL_PROD)
    print('QUANTITY OF ITEMS YOU BOUGHT ARE: ',TOTAL_QUAN)
    print('ITEM IDIVIDUAL AMOUNT: ',TOTAL_PRICE)
    all = sum(TOTAL_PRICE)
    if all > 3000 :
      all1 = all/100
      all2 = all1 *  0.15
      all3 = all - all2
      print('YOU GOT DISCOUNT OF 15% AND YOUR TOTAL BILLS IS: ',all3)
    else:
      all5 = all
      print('YOUR TOTAL BILLS IS: ',all5)
    print('THANK YOU FOR SHOPPING FROM OUR MART.')
    print('HAVE A NICE DAY ',self.cust_name,'.')
    


#DCs
print('------ WHO IS USING SHOPKEEPER OR CUSTOMER:')
ask_who = input('ENTER WHO: ')
if ask_who == 'SHOPKEEPER' or ask_who == 'Shopkeeper' or ask_who == 'shopkeeper':
  shopke = shop()
  shopke.SHOPE()

elif ask_who == 'CUSTOMER' or ask_who == 'Customer' or ask_who == 'customer':
  print('-------------- HELLO WORLD MART --------------')
  cust_name = input('ENTER YOUR FULL NAME(IN UPPER CASE LETTERS): ')
  cust_phno = input('ENTER YOUR PHONE NO: ')
  details = inventory(cust_name,cust_phno)
  print('')
  print('')
  details.customer_details()
  details.Car()
