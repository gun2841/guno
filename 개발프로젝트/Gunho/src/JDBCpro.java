import java.awt.*;
import java.awt.event.*;
import java.util.*;
import java.sql.*;
import javax.swing.*;
import java.awt.FlowLayout;
import java.awt.Font;
import java.util.Calendar;
import javax.swing.JFrame;
import javax.swing.JLabel;


@SuppressWarnings("serial")
class JDBCpro extends JFrame implements ActionListener
{
       String [] days = {"일","월","화","수","목","금","토"}; // 요일을 나타내기 위한 배열
       int year,month,day,todays,memoday=0;  // 년, 월 , 일, 오늘, 메모한날짜 알기
       Font f; // 폰트
       Calendar today;
       Calendar cal;
       JButton btnBefore,btnAfter; // 저번 달, 다음 달
       JButton btnAdd,btnDel,btnUpdate; // 메모추가, 메모삭제, 메모수정
       JButton[] calBtn = new JButton[49]; // 달력 버튼 49개 요일 + 날짜
       JLabel time;
       JPanel panSouth;
       JPanel panNorth;
       JPanel panCenter;             
       JTextField txtMonth,txtYear;
       // 글자를 넣을수있는 텍스트 필드 년 월 메모부분
       JTextArea txtWrite; // 메모를 넣는 부분
       
       
       BorderLayout bLayout= new BorderLayout();     
     
     
       
       //Database 연동부
       String driver = "com.mysql.jdbc.Driver";
       String url = "jdbc:mysql://localhost:3306/mysql";
       String user = "root";
       String pwd = "1234";
       ResultSet rs = null;    

       Connection con = null;
       Statement stmt = null;
  
       String sql;
       
       public JDBCpro(){
             today = Calendar.getInstance(); 
             cal = new GregorianCalendar();
             year = today.get(Calendar.YEAR);
             month = today.get(Calendar.MONTH)+1;//1월의 값이 0 
             panNorth = new JPanel();
             panNorth.add(btnBefore = new JButton(" ← "));            
             panNorth.add(txtYear = new JTextField(year+"년"));
             panNorth.add(txtMonth = new JTextField( month+"월"));
             f=new Font("SANS_SERIF",Font.PLAIN,30); //년가 월을 표시하는 텍스트 필드의 글자 속성
             txtYear.setFont(f);
             txtMonth.setFont(f);
             
             txtYear.setEnabled(false); // 년과 월을 선택 비활성화하여 숫자 수정을 불가피한다.
             txtMonth.setEnabled(false);
             
             panNorth.add(btnAfter = new JButton(" → "));
             add(panNorth,"North");
             // 날
             panCenter = new JPanel(new GridLayout(7,7));
             f=new Font("SERIF",Font.PLAIN,30);
             gridInit();
             calSet();
             hideInit();
             add(panCenter,"Center");
             panSouth = new JPanel(); 
             panSouth.add(btnAdd = new JButton("메모추가"));
             panSouth.add(btnDel = new JButton("메모삭제"));
             panSouth.add(btnUpdate = new JButton("메모수정"));
             panSouth.add(txtWrite = new JTextArea());
             txtWrite.setPreferredSize(new Dimension(150,50));
             //메모를 입력받을 텍스트 박스를 가로 150 세로 50 생성
             add(panSouth,"South");
             btnBefore.addActionListener(this);
             btnAfter.addActionListener(this);
             btnAdd.addActionListener(this);	//메모추가
             btnDel.addActionListener(this);	//메모삭제
             btnUpdate.addActionListener(this);	//메모삭제
             setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
             setTitle("스케쥴러");
             setBounds(200,200,500,500);	//(x,y,가로,세로) 프레임창의 위치
             setVisible(true); 
       }
       public void calSet(){ //달력초기화
    	   f=new Font("SERIF",Font.PLAIN,30);
             cal.set(Calendar.YEAR,year);
             cal.set(Calendar.MONTH,(month-1));
             cal.set(Calendar.DATE,1);
             int dayOfWeek = cal.get(Calendar.DAY_OF_WEEK);
             int j=0;
             int hopping=0;
             calBtn[0].setForeground(new Color(255,0,0));//일요일 "일" red
             calBtn[6].setForeground(new Color(0,0,255));//토요일 "토" blue
             for(int i=cal.getFirstDayOfWeek();i<dayOfWeek;i++){  j++;  }
             hopping=j;
             for(int kk=0;kk<hopping;kk++){
                    calBtn[kk+7].setText("");
             }
             for(int i=cal.getMinimum(Calendar.DAY_OF_MONTH);
                           i<=cal.getMaximum(Calendar.DAY_OF_MONTH);i++){
                 cal.set(Calendar.DATE,i);
                    if(cal.get(Calendar.MONTH) !=month-1){
                           break;
                    }
                    dbConnect();
                    todays=i;
                    checkday();
                    if(memoday==1){	//memo있는 날은 초록
                           calBtn[i+6+hopping].setForeground(new Color(0,255,255));                         
                    }
                    else{
                           calBtn[i+6+hopping].setForeground(new Color(0,0,0));
                           if((i+hopping-1)%7==0){//일요일
                                 calBtn[i+6+hopping].setForeground(new Color(255,0,0));
                           }
                           if((i+hopping)%7==0){//토요일
                                 calBtn[i+6+hopping].setForeground(new Color(0,0,255));
                           }
                    }
                    calBtn[i+6+hopping].setText((i)+"");
             }
 
       }
       
       public void actionPerformed(ActionEvent cook){   //액션 누르는걸cook 눌렀을때
    	   
             if(cook.getSource() == btnBefore){	// 이전달로 가기위한 소스부
                    this.panCenter.removeAll();
                    calInput(-1);				//달을 하나 빼준다
                    gridInit();
                    panelInit();               
                    calSet();
                    hideInit();
                    this.txtYear.setText(year+"년");
                    this.txtMonth.setText(month+"월");                   
             }                   
             else if(cook.getSource() == btnAfter){	// 다음 달로 가기위한 소스부
                    this.panCenter.removeAll();
                    calInput(1);				//달을 하나 더해준다.
                    gridInit();
                    panelInit();
                    calSet();
                    hideInit();
                    this.txtYear.setText(year+"년");
                    this.txtMonth.setText(month+"월");                                       
             }
             else if(cook.getSource() == btnAdd){ // 메모추가
                    dbConnect();
                    add();
                    calSet();
                    txtWrite.setText(""); 
             }
             else if(cook.getSource() == btnDel){ // 삭제
                    dbConnect();
                    del();
                    calSet();
                    txtWrite.setText("");
             }
             else if(cook.getSource() == btnUpdate){ // 수정
                 dbConnect();
                 update();
                 calSet();
                 txtWrite.setText("");
             }
 
             else if(Integer.parseInt(cook.getActionCommand()) >= 1 && 
                    Integer.parseInt(cook.getActionCommand()) <=31){
                    day = Integer.parseInt(cook.getActionCommand());
                    System.out.println(day);
                    dbConnect();               
                    searchmemo();
                    calSet();
             }      
       }

       public void hideInit(){ // 안찍힌 버튼 false로 초기화~
             for(int i = 0 ; i < calBtn.length;i++){
                    if((calBtn[i].getText()).equals(""))
                           calBtn[i].setEnabled(false); 
             }
       }
       public void gridInit(){// 판초기화
         for(int i = 0 ; i < days.length;i++)
               panCenter.add(calBtn[i] = new JButton(days[i]));                  
           for(int i = days.length ; i < 49;i++){                
                    panCenter.add(calBtn[i] = new JButton(""));                   
                    calBtn[i].addActionListener(this);
             }              
       }
       public void panelInit(){ // 초기화
         GridLayout gridLayout1 = new GridLayout(7,7);
         panCenter.setLayout(gridLayout1);   
       }
       public void calInput(int gap){
              if (gap==-1 || gap ==1)
              {
            	  month+=(gap);
            	  if (month<=0)
            	  {
                      month = 12;
                      year  =year- 1;
            	  }
            	  else if (month>=13)
            	  {
                      month = 1;
                      year =year+ 1;
            	  }
              }
              else if(gap == 12){	year++;	}
              else if(gap == -12){	year--;	}     
       }
       public void dbConnect(){ // 데이터베이스와 연결!
             try{
                    Class.forName(driver);
                    con = DriverManager.getConnection(url,user,pwd);
                    stmt = con.createStatement();    
             }catch(Exception ex){
                    ex.printStackTrace();
             }
       }
       public void add(){ // 해당하는 년,월,일에 메모를추가
             try{
                    String temp = txtWrite.getText();
                    if(temp.equals("")){
                           JOptionPane.showMessageDialog(null,"내용이 없습니다.");
                           return;
                    } 
                     sql = "insert into memo (memo,year,month,day) values (";                                                              
                     sql += "'"+temp+"',";
                     sql += "" +year +",";
                     sql += "" +month +",";
                     sql += "" +day +");";
                     System.out.println(sql);
                     stmt.executeUpdate(sql);  
                     stmt.close();
                     con.close();     
             }catch(Exception e){
                    e.printStackTrace();
             }
       }
       public void update(){ // 해당 연,월,일에 수정
           try{
        	   String temp = txtWrite.getText();
              if(temp.equals("")){
                      JOptionPane.showMessageDialog(null,"내용이 없습니다.");
                      return;
               }   
                   sql = "update memo set memo =";
                   sql += "'"+temp +"'";
                   sql += " where year=";                                                              
                   sql += year +" and month=";
                   sql += month +" and day=";
                   sql += +day +";";
                   System.out.println(sql);
                   stmt.executeUpdate(sql);        
                   stmt.close();
                   con.close();              
           }
           catch(Exception e)
           {
                  e.printStackTrace();
           }
     }
       public void del(){ // 선택한거 삭제!
             try{
                     sql = "delete from memo where year=";                                                              
                     sql += year +" and month=";
                     sql += month +" and day=";
                     sql += +day +";";
                     System.out.println(sql);
                     stmt.executeUpdate(sql);        
                     stmt.close();
                     con.close();              
             }
             catch(Exception e)
             {
                    e.printStackTrace();
             }
       }
       public void searchmemo(){
             try{
       
                     sql = "select memo from memo where year=";
                     sql += year +" and month=";
                     sql += month +" and day=";
                     sql += "" +day +";";
                     System.out.println(sql);
                     rs=stmt.executeQuery(sql);
                     String gettemp="";

                    while(rs.next()){
                           gettemp+=rs.getString("memo")+"  ";                         
                     }
                           txtWrite.setText(gettemp);
                     
                     stmt.close();
                     con.close();
 
             }catch(Exception e){
                    e.printStackTrace();
             }
       }
       public void checkday(){
             sql = "select * from memo where year=";
             sql += year +" and month=";
             sql += month +" and day=";
             sql += "" +todays +";";
              try{
                     rs=stmt.executeQuery(sql);
                     if(rs.next()){
                            memoday=1;
                     }
                     else memoday=0;
              }
              catch(Exception e)
              {
                     e.printStackTrace();
              }
 }
       public static void main(String[] args){
             JDBCpro abcde = new JDBCpro();
             abcde.show();
       
       }  
}
