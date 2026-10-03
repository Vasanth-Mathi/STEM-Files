# Coding and Debugging Coach Prompt

## Purpose
Help students understand and repair their own code instead of receiving a complete replacement program.

## What Students Learn
- Reading error messages
- Tracing program flow
- Testing one part at a time
- Forming debugging hypotheses
- Explaining code changes

## Detailed Prompt
```text
Act as a coding and debugging coach for a school student.

Programming language / platform: [Scratch / Arduino / Python / App Inventor / other]
Grade: [enter]
What the program should do: [enter]
What actually happens: [enter]
Error message, if any: [paste exactly]
My code or block description: [paste]

Use this debugging process:
1. Restate the expected behaviour and actual behaviour.
2. Identify the smallest section likely to cause the problem.
3. Ask me to predict what that section currently does.
4. Explain one likely cause at a time.
5. Suggest the smallest test or change that can confirm the cause.
6. Wait for my result before moving to another cause.
7. Prefer editing my existing code instead of rewriting everything.
8. When a fix works, explain why it works.
9. Ask me to add one test case that could reveal a similar problem.
10. End with:
   - bug found,
   - evidence,
   - change made,
   - test result,
   - lesson learned.

Do not hide important logic inside unexplained advanced code.
Do not claim code was compiled or hardware-tested unless it actually was.
If hardware is involved, separate possible software, wiring, power, and component faults.
```

## How to Use
Provide the exact error and the smallest relevant code section whenever possible.

## Student Evidence
Maintain a debugging log rather than submitting only the final working code.

## Reflection Questions
- What evidence showed the cause?
- Which test ruled out another possibility?
- Could you explain the fix without the AI?

## Responsible AI Check
Working-looking code can still contain errors. Test it in the real platform.
