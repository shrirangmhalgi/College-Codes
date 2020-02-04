package com.assignment1;

public class FuzzyClass {
    private Float memberFunction;
    private String name;

    public FuzzyClass(Float memberFunction, String name) {
            this.memberFunction = memberFunction;
            this.name = name;
    }

    public Float getMemberFunction() {
            return memberFunction;
    }

    public void setMemberFunction(Float memberFunction) {
            this.memberFunction = memberFunction;
    }

    public String getName() {
            return name;
    }

    public void setName(String name) {
            this.name = name;
    }
}
