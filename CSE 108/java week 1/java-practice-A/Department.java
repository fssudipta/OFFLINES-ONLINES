public class Department {
    private int id;
    private String name;
    private Employee[] employees;
    private int employeeCount;
    private static int totalDepartments;
    private static double totalSalary;

    // there can be at most 20 departments
    private static final int MAX_DEPARTMENTS = 20;

    // you are not allowed to write any other constructor
    public Department(int id, String name) {
        if (totalDepartments < MAX_DEPARTMENTS) {
            this.id = id;
            this.name = name;
            this.employees = new Employee[10];
            this.employeeCount = 0;
            totalDepartments++;
        } else {
            throw new RuntimeException("Cannot create more than 20 departments");
        }
    }

    public void addEmployee(Employee e) {
        if (employeeCount < employees.length) {
            employees[employeeCount++] = e;
            totalSalary += e.getSalary();
        } else {
            throw new RuntimeException("Cannot add more employees to the department");
        }
    }

    public double getDepartmentSalary() {
        double departmentSalary = 0;
        for (int i = 0; i < employeeCount; i++) {
            departmentSalary += employees[i].getSalary();
        }
        return departmentSalary;
    }

    public Employee getMaxSalaryEmployee() {
        if (employeeCount == 0) {
            return null;
        }
        Employee maxSalaryEmployee = employees[0];
        for (int i = 1; i < employeeCount; i++) {
            if (employees[i].getSalary() > maxSalaryEmployee.getSalary()) {
                maxSalaryEmployee = employees[i];
            }
        }
        return maxSalaryEmployee;
    }

    public static double getTotalSalary() {
        return totalSalary;
    }
}
