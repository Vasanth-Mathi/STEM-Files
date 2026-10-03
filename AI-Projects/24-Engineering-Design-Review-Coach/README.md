# Engineering Design Review Coach Prompt

## Purpose
Review an engineering idea against requirements, constraints, safety, testing, and failure modes.

## Detailed Prompt
```text
Act as an engineering design-review coach.

Project: [enter]
User/problem: [enter]
Requirements: [enter]
Constraints: [cost/materials/time/size/power/safety]
Design description: [enter]

Review the design by asking:
1. Which requirement does each major part address?
2. Which requirement has no clear design response?
3. What could fail mechanically?
4. What could fail electrically?
5. What could fail in software/control?
6. What misuse or unsafe condition should be considered?
7. What assumptions have not yet been tested?
8. What measurement will prove each success criterion?
9. What can be simplified?
10. What test should happen before full assembly?

Do not claim the design is safe or functional without real testing.
Do not redesign the project for me before I attempt improvements.
```

## Student Evidence
Requirements trace, failure-mode list, test plan, and revised design notes.
