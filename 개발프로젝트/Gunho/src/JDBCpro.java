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
       String [] days = {"��","��","ȭ","��","��","��","��"}; // ������ ��Ÿ���� ���� �迭
       int year,month,day,todays,memoday=0;  // ��, �� , ��, ����, �޸��ѳ�¥ �˱�
       Font f; // ��Ʈ
       Calendar today;
       Calendar cal;
       JButton btnBefore,btnAfter; // ���� ��, ���� ��
       JButton btnAdd,btnDel,btnUpdate; // �޸��߰�, �޸����, �޸����
       JButton[] calBtn = new JButton[49]; // �޷� ��ư 49�� ���� + ��¥
       JLabel time;
       JPanel panSouth;
       JPanel panNorth;
       JPanel panCenter;             
       JTextField txtMonth,txtYear;
       // ���ڸ� �������ִ� �ؽ�Ʈ �ʵ� �� �� �޸�κ�
       JTextArea txtWrite; // �޸� �ִ� �κ�
       
       
       BorderLayout bLayout= new BorderLayout();     
     
     
       
       //Database ������
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
             month = today.get(Calendar.MONTH)+1;//1���� ���� 0 
             panNorth = new JPanel();
             panNorth.add(btnBefore = new JButton(" �� "));            
             panNorth.add(txtYear = new JTextField(year+"��"));
             panNorth.add(txtMonth = new JTextField( month+"��"));
             f=new Font("SANS_SERIF",Font.PLAIN,30); //�Ⱑ ���� ǥ���ϴ� �ؽ�Ʈ �ʵ��� ���� �Ӽ�
             txtYear.setFont(f);
             txtMonth.setFont(f);
             
             txtYear.setEnabled(false); // ��� ���� ���� ��Ȱ��ȭ�Ͽ� ���� ������ �Ұ����Ѵ�.
             txtMonth.setEnabled(false);
             
             panNorth.add(btnAfter = new JButton(" �� "));
             add(panNorth,"North");
             // ��
             panCenter = new JPanel(new GridLayout(7,7));
             f=new Font("SERIF",Font.PLAIN,30);
             gridInit();
             calSet();
             hideInit();
             add(panCenter,"Center");
             panSouth = new JPanel(); 
             panSouth.add(btnAdd = new JButton("�޸��߰�"));
             panSouth.add(btnDel = new JButton("�޸����"));
             panSouth.add(btnUpdate = new JButton("�޸����"));
             panSouth.add(txtWrite = new JTextArea());
             txtWrite.setPreferredSize(new Dimension(150,50));
             //�޸� �Է¹��� �ؽ�Ʈ �ڽ��� ���� 150 ���� 50 ����
             add(panSouth,"South");
             btnBefore.addActionListener(this);
             btnAfter.addActionListener(this);
             btnAdd.addActionListener(this);	//�޸��߰�
             btnDel.addActionListener(this);	//�޸����
             btnUpdate.addActionListener(this);	//�޸����
             setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
             setTitle("�����췯");
             setBounds(200,200,500,500);	//(x,y,����,����) ������â�� ��ġ
             setVisible(true); 
       }
       public void calSet(){ //�޷��ʱ�ȭ
    	   f=new Font("SERIF",Font.PLAIN,30);
             cal.set(Calendar.YEAR,year);
             cal.set(Calendar.MONTH,(month-1));
             cal.set(Calendar.DATE,1);
             int dayOfWeek = cal.get(Calendar.DAY_OF_WEEK);
             int j=0;
             int hopping=0;
             calBtn[0].setForeground(new Color(255,0,0));//�Ͽ��� "��" red
             calBtn[6].setForeground(new Color(0,0,255));//����� "��" blue
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
                    if(memoday==1){	//memo�ִ� ���� �ʷ�
                           calBtn[i+6+hopping].setForeground(new Color(0,255,255));                         
                    }
                    else{
                           calBtn[i+6+hopping].setForeground(new Color(0,0,0));
                           if((i+hopping-1)%7==0){//�Ͽ���
                                 calBtn[i+6+hopping].setForeground(new Color(255,0,0));
                           }
                           if((i+hopping)%7==0){//�����
                                 calBtn[i+6+hopping].setForeground(new Color(0,0,255));
                           }
                    }
                    calBtn[i+6+hopping].setText((i)+"");
             }
 
       }
       
       public void actionPerformed(ActionEvent cook){   //�׼� �����°�cook ��������
    	   
             if(cook.getSource() == btnBefore){	// �����޷� �������� �ҽ���
                    this.panCenter.removeAll();
                    calInput(-1);				//���� �ϳ� ���ش�
                    gridInit();
                    panelInit();               
                    calSet();
                    hideInit();
                    this.txtYear.setText(year+"��");
                    this.txtMonth.setText(month+"��");                   
             }                   
             else if(cook.getSource() == btnAfter){	// ���� �޷� �������� �ҽ���
                    this.panCenter.removeAll();
                    calInput(1);				//���� �ϳ� �����ش�.
                    gridInit();
                    panelInit();
                    calSet();
                    hideInit();
                    this.txtYear.setText(year+"��");
                    this.txtMonth.setText(month+"��");                                       
             }
             else if(cook.getSource() == btnAdd){ // �޸��߰�
                    dbConnect();
                    add();
                    calSet();
                    txtWrite.setText(""); 
             }
             else if(cook.getSource() == btnDel){ // ����
                    dbConnect();
                    del();
                    calSet();
                    txtWrite.setText("");
             }
             else if(cook.getSource() == btnUpdate){ // ����
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

       public void hideInit(){ // ������ ��ư false�� �ʱ�ȭ~
             for(int i = 0 ; i < calBtn.length;i++){
                    if((calBtn[i].getText()).equals(""))
                           calBtn[i].setEnabled(false); 
             }
       }
       public void gridInit(){// ���ʱ�ȭ
         for(int i = 0 ; i < days.length;i++)
               panCenter.add(calBtn[i] = new JButton(days[i]));                  
           for(int i = days.length ; i < 49;i++){                
                    panCenter.add(calBtn[i] = new JButton(""));                   
                    calBtn[i].addActionListener(this);
             }              
       }
       public void panelInit(){ // �ʱ�ȭ
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
       public void dbConnect(){ // �����ͺ��̽��� ����!
             try{
                    Class.forName(driver);
                    con = DriverManager.getConnection(url,user,pwd);
                    stmt = con.createStatement();    
             }catch(Exception ex){
                    ex.printStackTrace();
             }
       }
       public void add(){ // �ش��ϴ� ��,��,�Ͽ� �޸��߰�
             try{
                    String temp = txtWrite.getText();
                    if(temp.equals("")){
                           JOptionPane.showMessageDialog(null,"������ �����ϴ�.");
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
       public void update(){ // �ش� ��,��,�Ͽ� ����
           try{
        	   String temp = txtWrite.getText();
              if(temp.equals("")){
                      JOptionPane.showMessageDialog(null,"������ �����ϴ�.");
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
       public void del(){ // �����Ѱ� ����!
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
